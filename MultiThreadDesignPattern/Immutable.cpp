/** 増補改訂版　Java 言語で学ぶデザインパターン入門　【マルチスレッド編】p90 Immutable.cpp **/
#include <thread>
#include <mutex>
#include <iostream>

class Person final
{
public:
	Person(const std::string& name, const std::string& address)
		:name_(name),
		 address_(address){}
	//セッターがない
	const std::string getName(){return name_;};
	const std::string getAddress(){return address_;};
private:
	std::string name_;
	std::string address_; 
};

int main()
{
	Person Akiemon("Akiemon","Tokyo");
	auto printPerson = [](Person& p){ std::cout<< "Name:" << p.getName() << std::endl <<"Address:" << p.getAddress() << std::endl;};
	std::thread printPersonThread(printPerson, std::ref(Akiemon));

	printPersonThread.join();
}