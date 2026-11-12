#define main seminar8_cli
#include "../SEMINARS/Seminar_8/analysis.cpp"
#undef main
#include <cassert>
int main()
{
    uint64_t count;
    for (uint64_t n=1; n<=1000; ++n)
    {
        assert(mystery(n,count)==formula(n));
    }
    mt19937 rng(123);
    for (int n=1; n<=100; ++n)
    {
        vector<double> a(n);
        for (double& x:a)
        {
            x=int(rng()%100)-50;
        }
        auto mm=minmax_element(a.begin(),a.end());
        assert(secret(a,count,false)==*mm.second-*mm.first);
        assert(secret(a,count,true)==*mm.second-*mm.first);
    }
    Matrix a={1,2,3,4},b={5,6,7,8},expected={19,22,43,50};
    assert(multiply(a,b,2,false,count)==expected);
    assert(multiply(a,b,2,true,count)==expected);
    unsigned it;
    for(uint64_t n=1; n<10000; ++n)
    {
        unsigned expected=0;
        for(uint64_t x=n;x;x>>=1)
        {
            ++expected;
        }
        assert(binary_digits(n,it)==expected);
    }
    assert(enigma({1,2,2,3},2,count));
    assert(!enigma({1,2,5,3},2,count));
    cout << "Independent boundary and randomized checks: OK\n";
}
