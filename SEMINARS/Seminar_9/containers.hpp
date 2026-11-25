#pragma once
#include <array>
#include <stdexcept>
#include <vector>
using namespace std;

template<size_t N>
class ArrayStack
{
    array<int,N> data{};
    size_t used = 0;
public:
    bool empty() const
    {
        return used == 0;
    }
    size_t size() const
    {
        return used;
    }
    void push(int value)
    {
        if (used == N)
        {
            throw overflow_error("stack overflow");
        }
        data[used++] = value;
    }
    int pop()
    {
        if (empty())
        {
            throw underflow_error("stack underflow");
        }
        return data[--used];
    }
    vector<int> values() const
    {
        return vector<int>(data.begin(),data.begin()+used);
    }
};

template<size_t N>
class TwoStacks
{
    array<int,N> data{};
    size_t left = 0;
    size_t right = N;
public:
    void push_left(int value)
    {
        if (left == right)
        {
            throw overflow_error("shared array full");
        }
        data[left++] = value;
    }
    void push_right(int value)
    {
        if (left == right)
        {
            throw overflow_error("shared array full");
        }
        data[--right] = value;
    }
    int pop_left()
    {
        if (left == 0)
        {
            throw underflow_error("left stack empty");
        }
        return data[--left];
    }
    int pop_right()
    {
        if (right == N)
        {
            throw underflow_error("right stack empty");
        }
        return data[right++];
    }
};

// Ring buffer: all N slots usable, count disambiguates empty and full.
template<size_t N>
class ArrayDeque
{
    static_assert(N > 0,"Capacity must be positive");
    array<int,N> data{};
    size_t head = 0;
    size_t count = 0;
public:
    bool empty() const
    {
        return count == 0;
    }
    size_t size() const
    {
        return count;
    }
    size_t head_index() const
    {
        return head;
    }
    size_t tail_index() const
    {
        return (head+count)%N;
    }
    void push_back(int value)
    {
        if (count == N)
        {
            throw overflow_error("deque overflow");
        }
        data[(head+count)%N] = value;
        ++count;
    }
    void push_front(int value)
    {
        if (count == N)
        {
            throw overflow_error("deque overflow");
        }
        head = (head+N-1)%N;
        data[head] = value;
        ++count;
    }
    int pop_front()
    {
        if (empty())
        {
            throw underflow_error("deque underflow");
        }
        int value = data[head];
        head = (head+1)%N;
        --count;
        return value;
    }
    int pop_back()
    {
        if (empty())
        {
            throw underflow_error("deque underflow");
        }
        --count;
        return data[(head+count)%N];
    }
    vector<int> values() const
    {
        vector<int> result;
        for (size_t i = 0; i < count; ++i)
        {
            result.push_back(data[(head+i)%N]);
        }
        return result;
    }
};
