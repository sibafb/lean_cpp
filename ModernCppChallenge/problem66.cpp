#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <thread>
#include <string_view>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <string>
#include <array>

#include <algorithm>

class logger
{
protected:
    logger() =  default;
public:
    static logger& instance()
    {
        static logger lg;
        return lg;
    };

    logger(logger const &) = delete;
    logger& operator=(logger const &) = delete;

    void log(std::string_view const & message)
    {
        std::lock_guard<std::mutex> lock(mt);
        std::cout << "LOG: " << message << std::endl;
    }

private:
    std::mutex mt;
};

class ticketing_machine
{
public:
    explicit ticketing_machine(int const start) : first_ticket(start), last_ticket(start) {}

    int next() { return last_ticket++; }
    int last() const { return last_ticket -1; }
    void reset() { last_ticket = first_ticket; }
private:
    int first_ticket;
    int last_ticket;
};

class customer
{
public:
    explicit customer(int const no) : number(no) {}

    int ticket_number() const noexcept { return number; }

    customer & operator=(const customer & other)
    {
        return *this;
    }

private:
    int const number;
    friend bool operator<(customer const & l, customer const & r);
};

bool operator<(customer const & l, customer const & r)
{
    return l.number > r.number;
}

int main()
{
    std::priority_queue<customer> customers;
    bool office_open = true;
    std::mutex mt;
    std::condition_variable cv;

    std::vector<std::thread> desks;
    for(int i = 1; i <= 3; ++i)
    {   
        desks.emplace_back([i, &office_open, &mt, &cv, &customers]() {
            std::random_device rd;
            auto seed_data = std::array<int, std::mt19937::state_size> {};
            std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
            std::seed_seq seq(std::cbegin(seed_data), std::cend(seed_data));
            std::mt19937 eng(seq);
            std::uniform_int_distribution<> ud(200, 300);

            logger::instance().log("desk " + std::to_string(i) + " open");

            while (office_open || !customers.empty())
            {
                std::unique_lock<std::mutex> locker(mt);

                cv.wait_for(locker, std::chrono::seconds(1), [&customers]() {return !customers.empty(); });

                if (!customers.empty())
                {
                    auto const c = customers.top();
                    customers.pop();

                    logger::instance().log("[-] desk " + std::to_string(i) + " handling customer " + std::to_string(c.ticket_number()));
                    logger::instance().log("[=] queue size: " + std::to_string(customers.size()));

                    locker.unlock();
                    cv.notify_one();

                    std::this_thread::sleep_for(std::chrono::milliseconds(ud(eng)));

                    logger::instance().log("[ ] desk " + std::to_string(i) + " done with customer " +std::to_string(c.ticket_number()));
                }
            }

            logger::instance().log("desk " + std::to_string(i) + " closed");
        });
    }

    std::thread store([&office_open, &customers, &cv](){
        ticketing_machine tm(100);
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size>{};
        std::generate(std::begin(seed_data),std::end(seed_data),std::ref(rd));
        std::seed_seq seq(std::cbegin(seed_data), std::cend(seed_data));
        std::mt19937 eng(seq);
        std::uniform_int_distribution<> ud(200, 500);

        for (int i = 1; i <= 25; ++i)
        {
            customer c(tm.next());
            customers.push(c);

            logger::instance().log("[+] new customer with ticket " + std::to_string(c.ticket_number()));
            logger::instance().log("[=] queue size: " + std::to_string(customers.size()));

            cv.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(ud(eng)));
        }
        office_open = false;
    });

    store.join();
    for (auto & desk :desks) desk.join();
}