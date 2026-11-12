#define main seminar6_main
#include "../Seminar_6/matrix_benchmark.cpp"
#undef main
#include <atomic>
#include <thread>
#include <numeric>
using namespace std;

// Same types, storage and ikj arithmetic as Seminar 6.
void rows(Matrix& a, const Matrix& b, const Matrix& c,
          int n, int start_row, int end_row, bool ijk)
{
    for (int i = start_row; i < end_row; ++i)
    {
        if (ijk)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    a[i*n+j] += b[i*n+k] * c[k*n+j];
                }
            }
        }
        else
        {
            for (int k = 0; k < n; ++k)
            {
                for (int j = 0; j < n; ++j)
                {
                    a[i*n+j] += b[i*n+k] * c[k*n+j];
                }
            }
        }
    }
}

int main()
{
    using Clock = chrono::high_resolution_clock;
    unsigned hw = thread::hardware_concurrency();
    unsigned workers = hw == 0 ? 1 : hw;
    cout << "SEMINAR 7 | GCC " << __VERSION__ << " | hardware threads=" << hw
         << " | used=" << workers << " | median of 5 runs\n";
    ofstream raw("seminar7_raw.csv");
    raw << "n,stage,threads,repeat,ms\n";
    cout << fixed << setprecision(3);
    // All threads are created here in main, outside multiplication loops.
    auto measure = [&](int n, int stage, unsigned count)
    {
        Matrix b(n*n), c(n*n), a(n*n), expected(n*n, 0);
        mt19937 rng(42);
        for (int i = 0; i < n*n; ++i)
        {
            b[i] = int(rng()%7)-3;
            c[i] = int(rng()%7)-3;
        }
        multiply_ikj(expected,b,c,n);
        vector<double> times;
        for (int repeat = 0; repeat < 5; ++repeat)
        {
            fill(a.begin(),a.end(),0);
            vector<thread> pool;
            atomic<bool> start_flag(false);
            atomic<unsigned> ready(0);
            auto start = Clock::now();
            if (stage == 1)
            {
                multiply_ikj(a,b,c,n);
            }
            else
            {
                pool.reserve(count);
                for (unsigned t = 0; t < count; ++t)
                {
                    int first = n*t/count;
                    int last = n*(t+1)/count;
                    pool.emplace_back([&,first,last]()
                    {
                        if (stage != 2)
                        {
                            ready.fetch_add(1,memory_order_release);
                            while (!start_flag.load(memory_order_acquire))
                            {
                                this_thread::yield();
                            }
                        }
                        rows(a,b,c,n,first,last,stage==5);
                    });
                }
                if (stage != 2)
                {
                    while (ready.load(memory_order_acquire) != count)
                    {
                        this_thread::yield();
                    }
                    start = Clock::now();
                    start_flag.store(true,memory_order_release);
                }
                for (thread& worker : pool)
                {
                    worker.join();
                }
            }
            double ms = chrono::duration<double,milli>(Clock::now()-start).count();
            if (a != expected)
            {
                throw runtime_error("Matrix verification failed");
            }
            raw << n << ',' << stage << ',' << count << ',' << repeat+1 << ','
                << setprecision(12) << ms << '\n';
            times.push_back(ms);
        }
        sort(times.begin(),times.end());
        return times[2];
    };
    cout << "STAGES n=800 | stage threads median_ms speedup | check\n";
    double baseline = measure(800,1,1);
    ofstream summary("seminar7_summary.csv");
    summary << "stage,threads,n,ms,speedup\n";
    for (int stage : {1,2,3,5,6})
    {
        unsigned count = stage==1 ? 1 : (stage==5 ? 4 : workers);
        double ms = stage==1 ? baseline : measure(800,stage,count);
        cout << stage << "       " << setw(3) << count << "      " << setw(10)
             << ms << "    " << baseline/ms << "    OK\n";
        summary << stage << ',' << count << ",800," << setprecision(12)
                << ms << ',' << baseline/ms << '\n';
    }
    cout << "SCALING | n 1thread_ms 4threads_ms T1/T4 | check\n";
    ofstream scale("seminar7_scaling.csv");
    scale << "n,t1_ms,t4_ms,speedup\n";
    for (int n : {300,500,800,1500})
    {
        double t1 = measure(n,1,1);
        double t4 = measure(n,3,4);
        cout << n << "   " << t1 << "    " << t4 << "    " << t1/t4 << "    OK\n";
        scale << n << ',' << setprecision(12) << t1 << ',' << t4 << ',' << t1/t4 << '\n';
    }
    cout << "All matrices match exactly. Timing with flag includes wake-up and join.\n";
    return 0;
}
