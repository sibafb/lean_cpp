# マルチスレッドデザインパターン

##  SingleThreadExecution
 - SingleThreadExecutionは単純に処理に排他を行うパターン。
 - 排他ロックがないとき

    ```shell
    build$ ./SingleThreadExecution 
    ~~~
     ******** BROKEN ******** No.29596914 : Alice, Canada
     ******** BROKEN ******** No.29596944 : Chris, Canada
    ~~~
    ```

- 排他ロックがあるとき

    ```shell
    build$ ./SingleThreadExecution 
    Alice BEGIN.
    Bobby BEGIN.
    Chris BEGIN.
    ```

    となり。破壊がおこらない。

##  Immutable

 - Immutableなクラスはメンバの値を変更できないクラスで、セッターを持たない。必須ではないが、下記の例ではfinalを追加して、継承もできなくしてある。

    ```cpp
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
    ```

## Guarded Suspension

 - Guarded　Suspensionは、ある条件が整うまで、スレッドの実行を停止するという意味のパターン。例として、キューを複数のスレッドが操作するとき、キューから取り出すときの操作にガードを入れて、キューが空の場合ガードされて取り出す操作を一時停止する。キューに値が入れば再起動する。などの一連の操作に取り入れられる。
 - コードではキューにリクエストを送信するClientThreadと、リクエストを受け取るServerThreadがあり、ClientThreadがキューに送信したリクエストをServerThreadが受け取る。というフローで、ServerThreadはリクエストがキューに積まれていない場合、待機状態になり、ClientThreadがリクエストを送信する（条件の変化）を待って再起動する。

    ```cpp
	Request getRequest()
	{
		while (m_dequeue.empty())
		{
			std::unique_lock<std::mutex> ul(m_mutex);
			m_cv.wait(ul);
		}
		Request ret = m_dequeue.front();
		m_dequeue.pop_front();
		return ret;
	}
	void putRequest(Request request)
	{
		std::unique_lock<std::mutex> ul(m_mutex);
		//サイズ制限をキュー側に設けるのが妥当だが、勉強用なので設けない
		m_dequeue.emplace_back(request);
		m_cv.notify_one();
	}
    ```

- std::unique_lock<std::mutex> ul(m_mutex) はここではないといけないのだろうか

## Balking

 - Balkingは複数のスレッドが重い処理を実行する前に、その処理をする必要がなければやめるというパターン。
 - 下記の実装例では、change よって変更された部分が、saveの前に変更されたかどうかの判定が入ってからdoSaveされる。これにより、複数スレッドでdoSaveを多重に行ってしまうことを防げる。

    ```cpp
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
    ```

## Producer-Consumer

 - Producer-Consumerパターンは、データの生産者と消費者をうまく回すようにするために、通信路となる中間クラスを設けるというパターン。
 - 下記の実装例では、Tableクラスによって排他やキューのサイズ制限が行われているために、Tableの利用クラス（makerとeater）は特に通信路の内容を気にせずに処理が可能となっている。

    ```cpp
 	class Table{
 	public:
		
		void put(std::string cake)
		{
			std::unique_lock<std::mutex> ul(m_mutex);
			while (m_bufferMaxSize <= m_buffer.size())
			{
				m_cv.wait(ul);
			}
			std::cout<< std::this_thread::get_id() <<"put."<<std::endl;
			m_buffer.emplace_back(cake);
			m_cv.notify_all();
		}
		std::string take()
		{
			std::unique_lock<std::mutex> ul(m_mutex);
			while (m_buffer.empty())
			{
				m_cv.wait(ul);
			}
			std::cout<< std::this_thread::get_id() <<"take."<<std::endl;
			std::string front = m_buffer.front();
			m_buffer.pop_front();
			m_cv.notify_all();
			return front;
		}
 ```

## Read-Writes Lock

## Thread-Per-Message

## Worker Thread

## Future

## Two-Phase Termination

## ThreadSpecific Storage

## Active Object