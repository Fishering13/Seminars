#include "containers.hpp"
#include <iostream>
#include <string>
using namespace std;

void show(const vector<int>& values)
{
    cout << '[';
    for (int x : values)
    {
        cout << x << ' ';
    }
    cout << ']';
}
int main()
{
    cout << "SEMINAR 9 | array capacity=6 | automatic demonstration\n";
    ArrayStack<6> s;
    cout << "10.1.1 STACK (bottom -> top)\n";
    for (int x : {4,1,3})
    {
        s.push(x);
        cout << "PUSH " << x << "  "; show(s.values());
        cout << " top=" << s.size() << '\n';
    }
    cout << "POP -> " << s.pop() << "  "; show(s.values()); cout << '\n';
    s.push(8); cout << "PUSH 8  "; show(s.values()); cout << '\n';
    cout << "POP -> " << s.pop() << "  "; show(s.values()); cout << '\n';
    cout << "10.1.2 TWO STACKS IN ONE ARRAY\n";
    TwoStacks<6> two;
    for (int x : {1,2,3,4})
    {
        two.push_left(x);
    }
    two.push_right(90); two.push_right(80);
    cout << "4 left + 2 right = full; pop_left=" << two.pop_left()
         << ", pop_right=" << two.pop_right() << '\n';
    cout << "10.1.3 QUEUE (front -> back), 1-based head/tail\n";
    ArrayDeque<6> q;
    auto print = [&]()
    {
        show(q.values());
        cout << " head=" << q.head_index()+1 << " tail=" << q.tail_index()+1
             << " count=" << q.size() << '\n';
    };
    for (int x : {4,1,3})
    {
        q.push_back(x); cout << "ENQUEUE " << x << "  "; print();
    }
    cout << "DEQUEUE -> " << q.pop_front() << "  "; print();
    q.push_back(8); cout << "ENQUEUE 8  "; print();
    cout << "DEQUEUE -> " << q.pop_front() << "  "; print();
    cout << "10.1.4 EMPTY/FULL DETECTION\n";
    ArrayDeque<2> tiny;
    try
    {
        tiny.pop_front();
    }
    catch (const underflow_error& e)
    {
        cout << "Empty removal rejected: " << e.what() << '\n';
    }
    tiny.push_back(10); tiny.push_back(20);
    try
    {
        tiny.push_back(30);
    }
    catch (const overflow_error& e)
    {
        cout << "Full insertion rejected: " << e.what() << '\n';
    }
    cout << "10.1.5 DEQUE\n";
    ArrayDeque<6> d;
    d.push_back(2); d.push_front(1); d.push_back(3);
    show(d.values());
    cout << " pop_back=" << d.pop_back() << " pop_front=" << d.pop_front() << '\n';
    cout << "Remaining: "; show(d.values()); cout << "\nFinished successfully.\n";
    return 0;
}
