/** 増補改訂版　Java 言語で学ぶデザインパターン入門　【マルチスレッド編】p140 Balking.cpp **/
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <functional>
#include <fstream>
#include <random>

using std::string;
using std::mutex;
using namespace std::literals::chrono_literals;

class Data
{
public:
	Data(string filename, string content) 
	{
		m_filename = filename;
		m_content = content;
	}
	void change(string newContent)
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		std::cout << "change newContent" <<std::endl;
		m_content = newContent;
		m_isChanged = true;
	}
	void save()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		if(!m_isChanged)
		{
			std::cout << std::this_thread::get_id() << " balking." << std::endl;
			return; //下の部分のdoSave処理をBalkしている。
		}
		doSave();
		m_isChanged = false;
	}
private:
	void doSave()
	{
		std::cout << std::this_thread::get_id() << " calls doSave. content = " << m_content << std::endl;
		std::ofstream writing_file;

		writing_file.open(m_filename, std::ios::out);
		writing_file << m_content << std::endl;
		writing_file.close();
	}
	string m_filename;
	string m_content;
	bool m_isChanged; 
	mutex m_mutex;
};

class SaverThread
{
public:
	SaverThread(string name, std::shared_ptr<Data> data)
		:m_data(data),
		m_isTerminationRequested(false),
		m_name(name),
		m_saverThread(m_run)
	{}

	~SaverThread(){}

	void join()
	{
		m_saverThread.join();
	}

	void detach(){
		m_saverThread.detach();
	}

	void requestTernimation()
	{
		m_isTerminationRequested = true;
	}

private:
	std::function<void()> m_run = [this]
	{
		while(!m_isTerminationRequested)
		{
			m_data->save();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	};

	bool m_isTerminationRequested = false;
	string m_name;
	std::shared_ptr<Data> m_data;
	std::thread m_saverThread;
};

class ChangeThread 
{
public:
	ChangeThread(string name, std::shared_ptr<Data> data)
		:m_data(data),
		m_isTerminationRequested(false),
		m_changerThread(m_run),
		m_name(name)
	{
	}
	~ChangeThread()
	{
	}

	void join()
	{
		m_changerThread.join();
	}

	void detach(){
		m_changerThread.detach();
	}

	void requestTernimation()
	{
		m_isTerminationRequested = true;
	}

private:
	bool m_isTerminationRequested = false;

	std::function<void()> m_run = [this]
	{
		int i = 0;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		
		while(!m_isTerminationRequested)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			m_data->change("NO." + std::to_string(i));
			std::this_thread::sleep_for(std::chrono::milliseconds(dist1(engine)));
			m_data->save();
			i++;
		}
	};

	std::shared_ptr<Data> m_data;
	std::random_device m_seed_gen;
  	std::default_random_engine engine{m_seed_gen()};
	std::uniform_int_distribution<> dist1{1,1000};

	string m_name;
	std::thread m_changerThread;
};

int main()
{
	std::shared_ptr<Data> data = std::make_shared<Data>("data.txt", "(empty)");
	ChangeThread ct("ChangerThread",data);
	SaverThread  st("SaverThread",data);

	std::this_thread::sleep_for(15s);
	
	ct.join();
	st.join();
}