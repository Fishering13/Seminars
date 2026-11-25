#define main seminar10_demo
#include "../SEMINARS/Seminar_10/main.cpp"
#undef main
#include <cassert>
#include <deque>
#include <random>
#include <algorithm>
using namespace std;
template<class Error,class F>
void rejects(F f)
{
    bool thrown = false;
    try
    {
        f();
    }
    catch (const Error&)
    {
        thrown = true;
    }
    assert(thrown);
}
int main()
{
    ArrayStack<6> s;
    rejects<underflow_error>([&]() { s.pop(); });
    for (int x=0; x<6; ++x)
    {
        s.push(x);
    }
    rejects<overflow_error>([&]() { s.push(7); });
    auto reversed=reverse_stack(s);
    assert(reversed.values()==vector<int>({5,4,3,2,1,0}));
    assert(s.values()==vector<int>({0,1,2,3,4,5}));
    assert(reverse_stack(ArrayStack<6>{}).empty());
    TwoStacks<6> two;
    rejects<underflow_error>([&]() { two.pop_left(); });
    rejects<underflow_error>([&]() { two.pop_right(); });
    for(int i=0;i<6;++i)
    {
        two.push_right(i);
    }
    rejects<overflow_error>([&]() { two.push_left(99); });
    for(int i=5;i>=0;--i)
    {
        assert(two.pop_right()==i);
        two.push_left(i);
    }
    rejects<overflow_error>([&]() { two.push_right(99); });
    ArrayDeque<7> d;
    deque<int> ref;
    mt19937 rng(42);
    for(int t=0;t<10000;++t)
    {
        unsigned op=rng()%4;
        int x=int(rng()%1000);
        if(op<2)
        {
            if(ref.size()==7)
            {
                rejects<overflow_error>([&]() { op ? d.push_front(x) : d.push_back(x); });
            }
            else if(op)
            {
                d.push_front(x);ref.push_front(x);
            }
            else
            {
                d.push_back(x);ref.push_back(x);
            }
        }
        else if(ref.empty())
        {
            rejects<underflow_error>([&]() { op==2 ? d.pop_front() : d.pop_back(); });
        }
        else if(op==2)
        {
            assert(d.pop_front()==ref.front());ref.pop_front();
        }
        else
        {
            assert(d.pop_back()==ref.back());ref.pop_back();
        }
        assert(d.values()==vector<int>(ref.begin(),ref.end()));
    }
    ArrayDeque<1> one;
    one.push_front(4);assert(one.pop_back()==4);
    one.push_back(5);assert(one.pop_front()==5);
    PriorityQueue q;
    vector<Job> jobs;
    for(size_t i=0;i<1000;++i)
    {
        Job job{int(i),int(rng()%11)-5,i};
        jobs.push_back(job);q.push(job.value,job.priority);
    }
    stable_sort(jobs.begin(),jobs.end(),[](const Job& a,const Job& b)
    {
        return a.priority>b.priority;
    });
    for(const Job& expected:jobs)
    {
        Job got=q.pop();assert(got.value==expected.value);
    }
    rejects<underflow_error>([&]() { q.pop(); });
    cout << "All tests passed: stack boundaries and reversal; shared capacity;\n"
         << "10000 random deque operations vs std::deque; capacity=1;\n"
         << "1000 priority jobs vs stable_sort; empty/full rejection.\n";
}
