#include <iostream>
#include <vector>
#include <assert.h>

template <class T>
class circular_buffer;

template <class T>
class circular_buffer_iterator
{
    using self_type = circular_buffer_iterator;
    using value_type = T;
    using reference = T&;
    using const_reference = T const&;
    using pointer = T*;
    using const_pointer = T const*;
    using iterator_category = std::random_access_iterator_tag;
    using defference_type = ptrdiff_t;

public:
    circular_buffer_iterator(circular_buffer<T> const & buf, size_t const pos, bool const last)
    : buffer_(buf), index_(pos), last_(last) {}

    self_type & operator++()
    {
        if(last_)
            throw std::out_of_range("Iterator cannot be incremented past the end of range.");
        index_ = (index_ + 1) % buffer_.data_.size();
        last_ = index_ == buffer_.next_pos();
        return *this;
    }

    self_type operator++(int)
    {
        self_type tmp = *this;
        ++*this;
        return tmp;
    }

    bool operator==(self_type const & other) const
    {
        assert(compatible(other));
        return index_ == other.index_ && last_ == other.last_;
    }

    bool operator!=(self_type const & other) const
    {
        return !(*this == other);
    }

    const_reference operator*() const
    {
        return buffer_.data_[index_];
    }

    const_pointer operator->() const 
    {
        return std::addressof(operator*());
    }
private:
    bool compatible(self_type const & other) const
    {
        return &buffer_ == &other.buffer_;
    }

    circular_buffer<T> const & buffer_;
    size_t index_;
    bool last_;
};

template <class T>
class circular_buffer
{
    using const_iterator = circular_buffer<T>;

public:
    circular_buffer() = delete;
    explicit circular_buffer(size_t const size) : data_(size) {}

    void clear() noexcept { head_ = -1; size_ = 0; }

    bool empty() const noexcept { return size_ == 0; }
    bool full() const noexcept { return size_ == data_.size(); }
    size_t capacity() const noexcept { return data_.size(); }
    size_t size() const noexcept { return size_; }

    void push(T const item)
    {
        head_ = next_pos();
        data_[head_] = item;
        if (size_ < data_.size()) size_++;
    }

    T pop()
    {
        if (empty()) throw std::runtime_error("empty buffer");

        auto pos = first_pos();
        size_--;
        return data_[pos];
    }

    const_iterator begin() const
    {
        return const_iterator(*this, first_pos(), empty());
    }

    const_iterator end() const
    {
        return const_iterator(*this, next_pos(), true);
    }

private:
    std::vector<T> data_;

    size_t head_ = -1;
    size_t size_ = 0;

    size_t next_pos() const noexcept
    { return size_ == 0 ? 0 : (head_ + 1) % data_.size(); }

    size_t first_pos() const noexcept
    { return size_ == 0 ? 0 : (head_ + data_.size() - size_ + 1) % data_.size(); }
    
    friend class circular_buffer_iterator<T>;
};

int main()
{
    circular_buffer<int> cbuf(5);
    cbuf.push(1);
    cbuf.push(2);
    cbuf.push(3);

    auto item = cbuf.pop();
    cbuf.push(4);
    cbuf.push(5);
    cbuf.push(6);
    cbuf.push(7);
    cbuf.push(8);

    item = cbuf.pop();
    item = cbuf.pop();
    item = cbuf.pop();

    item = cbuf.pop();
    item = cbuf.pop();
    cbuf.push(9);
}