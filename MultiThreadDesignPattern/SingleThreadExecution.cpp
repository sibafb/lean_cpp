/** 増補改訂版　Java 言語で学ぶデザインパターン入門　【マルチスレッド編】p58 SingleThreadExecution.cpp **/
#include <thread>
#include <mutex>
#include <iostream>

class Gate 
{
public:
	void pass(std::string name, std::string address)
	{
		//この排他制御を入れるか入れないかで結果が変わる。
		std::lock_guard<std::mutex> lock(m_gate);
		m_counter++;
		m_name = name;
		m_address = address;
		check();
	}
	std::string toString()
	{
		return "No." + std::to_string(m_counter) + " : " + m_name + ", " + m_address;
	}
private:
	int m_counter = 0;
	std::string m_name = "Nobody";
	std::string m_address = "Nowhere";
	std::mutex m_gate;

	void check() 
	{
		if(m_name.at(0) != m_address.at(0))
		{
			std::cout << " ******** BROKEN ******** " << toString() <<std::endl;
		}
	}
};

int main()
{
    
	auto PasstheGate = [](Gate & gate, const std::string& name, const std::string& address) 
	{
		std::cout << name << " BEGIN." << std::endl;
		while(true){
			gate.pass(name, address);
		}
	};

	Gate gate;	

	std::string Alice_name = "Alice";
	std::string Alice_address = "Alaska";
	std::thread AliceThread(PasstheGate, std::ref(gate), std::ref(Alice_name), std::ref(Alice_address));
	std::string Bobby_name = "Bobby";
	std::string Bobby_address = "Brazil";	
 	std::thread BobbyThread(PasstheGate, std::ref(gate), std::ref(Bobby_name), std::ref(Bobby_address));
	std::string Chris_name = "Chris";
	std::string Chris_address = "Canada";	
	std::thread ChrisThread(PasstheGate, std::ref(gate), std::ref(Chris_name), std::ref(Chris_address));

	AliceThread.join();
	BobbyThread.join();
	ChrisThread.join();

	return 0;
}