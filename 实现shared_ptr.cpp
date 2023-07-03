#include <bits/stdc++.h>
using namespace std;
class shared_count
{
public:
    shared_count() : count_(1) {}
    void add_count()
    {
        ++count_;
    }
    long reduce_count()
    {
        return --count_;
    }
    long get_count() const
    {
        return count_;
    }

private:
    long count_;
};
template <typename T>
class smart_ptr
{
private:
    T *ptr_;
    shared_count *shared_count_;

public:
    template <typename U>
    friend class smart_ptr;
    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr)
    {
        if (ptr)
        {
            shared_count_ = new shared_count();
        }
    }
    ~smart_ptr()
    {
        if (ptr_ && !shared_count_->reduce_count())
        {
            delete ptr_;
            delete shared_count_;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U> &other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.ptr_;
        if (ptr_)
        {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    smart_ptr &operator=(smart_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }
    void swap(smart_ptr &rhs)
    {
        std::swap(ptr_, rhs.ptr_);
        std::swap(shared_count_, rhs.shared_count_);
    }
    T &operator*() const
    {
        return *ptr_;
    }
    T *operator->() const
    {
        return ptr_;
    }
    operator bool() const
    {
        return ptr_;
    }
    T *get() const
    {
        return ptr_;
    }
    long use_count() const
    {
        if (ptr_)
        {
            return shared_count_->get_count();
        }
        else
        {
            return 0;
        }
    }
};
class shape
{
public:
    ~shape()
    {
    }
};
class circle : public shape
{
public:
    ~circle()
    {
        cout << "~circle()" << endl;
    }
};
int main()
{
    smart_ptr<circle> ptr1(new circle());
    cout << ptr1.use_count() << endl;
    smart_ptr<shape> ptr2;
    cout << ptr2.use_count() << endl;
    ptr2 = ptr1;
    cout << ptr2.use_count() << endl;
    cout << ptr1.use_count() << endl;
    return 0;
}
