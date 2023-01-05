#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;
namespace ch = std::chrono;

template<typename Duration>
bool is_older_than(fs::path const & path, Duration const duration)
{
    auto ftimeduration = fs::last_write_time(path).time_since_epoch();
    auto nowduration = (ch::system_clock::now() - duration).time_since_epoch();
    return ch::duration_cast<Duration>(nowduration -ftimeduration).count() > 0;
}

template<typename Duration>
void remove_files_older_than(fs::path const & path, Duration const duration)
{
    try
    {
        if(fs::exists(path))
        {
            if(is_older_than(path, duration))
            {
                fs::remove(path);
            }
            else if(fs::is_directory(path))
            {
                for(auto const & entry : fs::directory_iterator(path))
                {
                    remove_files_older_than(entry, duration);
                }
            }
        }
    }
    catch (std::exception const & ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

int main()
{
    using namespace std::chrono_literals;
    auto path = R"(../Test/)";
    remove_files_older_than(path, 1h + 20min);
}