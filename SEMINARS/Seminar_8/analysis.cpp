#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>
using namespace std;
using Clock = chrono::high_resolution_clock;
using Matrix = vector<double>;

uint64_t mystery(uint64_t n, uint64_t& operations)
{
    uint64_t sum = 0;
    operations = 0;
    for (uint64_t i = 1; i <= n; ++i)
    {
        sum += i*i;
        ++operations;
    }
    return sum;
}
uint64_t formula(uint64_t n)
{
    // n <= 1000000: products fit uint64_t.
    return n*(n+1)*(2*n+1)/6;
}
double secret(const vector<double>& a, uint64_t& comparisons, bool pairs)
{
    if (a.empty())
    {
        throw invalid_argument("Nonempty array required");
    }
    comparisons = 0;
    double lo = a[0], hi = a[0];
    size_t i = 1;
    if (pairs && a.size()%2 == 0)
    {
        ++comparisons;
        if (a[0] < a[1])
        {
            hi = a[1];
        }
        else
        {
            lo = a[1];
        }
        i = 2;
    }
    for (; i < a.size(); i += pairs ? 2 : 1)
    {
        double small = a[i], large = a[i];
        if (pairs)
        {
            ++comparisons;
            if (a[i] > a[i+1])
            {
                small = a[i+1];
            }
            else
            {
                large = a[i+1];
            }
        }
        comparisons += 2;
        if (small < lo)
        {
            lo = small;
        }
        if (large > hi)
        {
            hi = large;
        }
    }
    return hi-lo;
}
bool enigma(const Matrix& a, int n, uint64_t& comparisons)
{
    comparisons = 0;
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            ++comparisons;
            if (a[i*n+j] != a[j*n+i])
            {
                return false;
            }
        }
    }
    return true;
}
Matrix multiply(const Matrix& a, const Matrix& b, int n,
                bool improved, uint64_t& additions)
{
    Matrix c(n*n,0);
    additions = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int first = 0;
            if (improved)
            {
                c[i*n+j] = a[i*n]*b[j];
                first = 1;
            }
            for (int k = first; k < n; ++k)
            {
                c[i*n+j] += a[i*n+k]*b[k*n+j];
                ++additions;
            }
        }
    }
    return c;
}
unsigned binary_digits(uint64_t n, unsigned& iterations)
{
    unsigned count = 1;
    iterations = 0;
    while (n > 1)
    {
        n /= 2;
        ++count;
        ++iterations;
    }
    return count;
}
int main()
{
    ofstream csv("seminar8_results.csv");
    csv << "task,n,original_ops,improved_ops,original_ms,improved_ms\n";
    cout << "SEMINAR 8 | operation counts and measured time | automatic input\n";
    cout << fixed << setprecision(6);
    uint64_t sink = 0;
    auto timed = [&](auto f)
    {
        auto start = Clock::now();
        f();
        return chrono::duration<double,milli>(Clock::now()-start).count();
    };
    cout << "1 Mystery | n sum multiplications | loop_ms formula_ms\n";
    for (uint64_t n : {10000,100000,1000000})
    {
        uint64_t ops, a, b;
        double t1 = timed([&]()
        {
            a=mystery(n,ops);
        });
        double t2 = timed([&]()
        {
            b=formula(n);
        });
        if (a!=b || ops!=n)
        {
            throw runtime_error("Mystery failed");
        }
        sink ^= a;
        cout << n << ' ' << a << ' ' << ops << " | " << t1 << ' ' << t2 << " OK\n";
        csv << "1," << n << ',' << ops << ",3," << t1 << ',' << t2 << '\n';
    }
    cout << "2 Secret | n original_comparisons pair_comparisons | milliseconds\n";
    for (int n : {1,2,5,10000,100000,1000000})
    {
        vector<double> a(n);
        mt19937 rng(42);
        for (double& x : a)
        {
            x = int(rng()%10000)-5000;
        }
        uint64_t c1,c2;
        double x,y;
        double t1=timed([&]()
        {
            x=secret(a,c1,false);
        });
        double t2=timed([&]()
        {
            y=secret(a,c2,true);
        });
        if (x!=y || c1!=2ULL*(n-1) || c2!= (n%2 ? 3ULL*(n-1)/2 : 3ULL*n/2-2))
        {
            throw runtime_error("Secret failed");
        }
        cout << n << ' ' << c1 << ' ' << c2 << " | " << t1 << ' ' << t2 << " OK\n";
        csv << "2," << n << ',' << c1 << ',' << c2 << ',' << t1 << ',' << t2 << '\n';
    }
    cout << "3 Enigma | n symmetric_comparisons first_mismatch_comparisons\n";
    for (int n : {1,100,500,1000})
    {
        Matrix a(n*n,1);
        uint64_t c1,c2;
        bool yes=enigma(a,n,c1);
        if (n>1)
        {
            a[1]=2;
        }
        bool no=enigma(a,n,c2);
        if (!yes || c1!=uint64_t(n)*(n-1)/2 || (n>1 && (no || c2!=1)))
        {
            throw runtime_error("Enigma failed");
        }
        cout << n << ' ' << c1 << ' ' << c2 << " OK\n";
        csv << "3," << n << ',' << c1 << ',' << c2 << ",0,0\n";
    }
    cout << "4 Matrix product | n original_additions improved_additions | milliseconds\n";
    for (int n : {1,32,64,128,256})
    {
        Matrix a(n*n),b(n*n),c,d;
        for (int i=0; i<n*n; ++i)
        {
            a[i]=i%5-2;
            b[i]=i%7-3;
        }
        uint64_t c1,c2;
        double t1=timed([&]()
        {
            c=multiply(a,b,n,false,c1);
        });
        double t2=timed([&]()
        {
            d=multiply(a,b,n,true,c2);
        });
        if (c!=d || c1!=uint64_t(n)*n*n || c2!=uint64_t(n)*n*(n-1))
        {
            throw runtime_error("Multiplication failed");
        }
        cout << n << ' ' << c1 << ' ' << c2 << " | " << t1 << ' ' << t2 << " OK\n";
        csv << "4," << n << ',' << c1 << ',' << c2 << ',' << t1 << ',' << t2 << '\n';
    }
    cout << "5 Binary | n bits iterations\n";
    for (uint64_t n : {1ULL,2ULL,3ULL,255ULL,256ULL,1024ULL,18446744073709551615ULL})
    {
        unsigned iterations;
        unsigned bits=binary_digits(n,iterations);
        cout << n << ' ' << bits << ' ' << iterations << " OK\n";
        csv << "5," << n << ',' << iterations << ',' << bits << ",0,0\n";
    }
    cout << "All checks passed. Checksum=" << sink << "\n";
    return 0;
}
