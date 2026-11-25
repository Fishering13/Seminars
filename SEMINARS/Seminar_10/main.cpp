#include "../Seminar_9/containers.hpp"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

template<size_t N>
ArrayStack<N> reverse_stack(ArrayStack<N> input)
{
    ArrayStack<N> output;
    while (!input.empty())
    {
        output.push(input.pop());
    }
    return output;
}
struct Job
{
    int value;
    int priority;
    size_t sequence;
};
struct LowerPriority
{
    bool operator()(const Job& a, const Job& b) const
    {
        if (a.priority != b.priority)
        {
            return a.priority < b.priority;
        }
        return a.sequence > b.sequence;
    }
};
class PriorityQueue
{
    priority_queue<Job,vector<Job>,LowerPriority> heap;
    size_t next = 0;
public:
    void push(int value, int priority)
    {
        heap.push({value,priority,next++});
    }
    bool empty() const
    {
        return heap.empty();
    }
    Job pop()
    {
        if (empty())
        {
            throw underflow_error("priority queue empty");
        }
        Job job = heap.top();
        heap.pop();
        return job;
    }
};
void print_values(const vector<int>& v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}
int main()
{
    cout << "SEMINAR 10 | automatic demonstration; integer values\n";
    cout << "1 REVERSE STACK (bottom -> top)\n";
    ArrayStack<6> original;
    for (int x : {4,1,3,8})
    {
        original.push(x);
    }
    auto reversed = reverse_stack(original);
    cout << "Input : "; print_values(original.values());
    cout << "Output: "; print_values(reversed.values());
    cout << "Output pop order: ";
    while (!reversed.empty())
    {
        cout << reversed.pop() << ' ';
    }
    cout << "\n2 PRIORITY QUEUE | larger priority served first; ties FIFO\n";
    PriorityQueue q;
    q.push(100,2); q.push(200,5); q.push(300,5); q.push(400,1);
    while (!q.empty())
    {
        Job job = q.pop();
        cout << "value=" << job.value << " priority=" << job.priority << '\n';
    }
    try
    {
        q.pop();
    }
    catch (const underflow_error& e)
    {
        cout << "Empty removal rejected: " << e.what() << '\n';
    }
    cout << "3 DEQUE | ring capacity=4 | front -> back\n";
    ArrayDeque<4> d;
    d.push_back(20); d.push_front(10); d.push_back(30); d.push_front(5);
    cout << "After four insertions: "; print_values(d.values());
    cout << "pop_front=" << d.pop_front() << " pop_back=" << d.pop_back() << '\n';
    d.push_back(40); d.push_front(1);
    cout << "After wrap-around: "; print_values(d.values());
    try
    {
        d.push_back(50);
    }
    catch (const overflow_error& e)
    {
        cout << "Full insertion rejected: " << e.what() << '\n';
    }
    cout << "Drain from front: ";
    while (!d.empty())
    {
        cout << d.pop_front() << ' ';
    }
    cout << "\nFinished successfully.\n";
    return 0;
}
