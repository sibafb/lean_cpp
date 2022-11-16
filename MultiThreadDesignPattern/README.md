# マルチスレッドデザインパターン

##  SingleThreadExecution

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

## Balking

## Producer-Consumer

## Read-Writes Lock

## Thread-Per-Message

## Worker Thread

## Future

## Two-Phase Termination

## ThreadSpecific Storage

## Active Object