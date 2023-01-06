template<typename T, typename F>
class priority_queue
{
    priority_queue(typename F)
    
    {
        data.clear();
    }

    void push(const T & a)
    {
        data.push_back(a);
    }
    void pop()
    {
        data.pop();
    }
    const T& top()
    {
        return data.end();
    }
    unsigned int& size()
    {
        return data.size();
    }
    bool empty()
    [
        return 
    ]

private:
    std::deque<T> data;
    F& compare(const T & a, const T & b);
}