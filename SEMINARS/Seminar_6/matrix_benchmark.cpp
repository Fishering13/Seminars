#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;
using Matrix = vector<double>;
using Kernel = void (*)(Matrix&, const Matrix&, const Matrix&, int);

// A = A + B*C. Matrices are separate, stored contiguously by rows.
void multiply_ijk(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

void multiply_ikj(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < n; ++k)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

void multiply_jik(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

void multiply_jki(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int j = 0; j < n; ++j)
    {
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

void multiply_kij(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

void multiply_kji(Matrix& a, const Matrix& b, const Matrix& c, int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                a[i * n + j] += b[i * n + k] * c[k * n + j];
            }
        }
    }
}

int main(int argc, char* argv[])
{
    const vector<string> names = {"ijk", "ikj", "jik", "jki", "kij", "kji"};
    const vector<Kernel> kernels = {multiply_ijk, multiply_ikj, multiply_jik,
                                   multiply_jki, multiply_kij, multiply_kji};
    vector<int> sizes = {20, 36, 52, 68, 84, 100, 150, 200, 250, 300,
                         500, 525, 550, 575, 600};
    if (argc == 2 && string(argv[1]) == "--quick")
    {
        sizes = {1, 2, 3, 10};
    }
    else if (argc != 1)
    {
        cerr << "Usage: matrix_benchmark [--quick]. No keyboard input needed.\n";
        return 1;
    }
    ofstream csv("matrix_timings.csv");
    if (!csv)
    {
        cerr << "Cannot write matrix_timings.csv\n";
        return 1;
    }
    csv << "n,order,repeat,seconds,checksum\n";
    csv << setprecision(12);
    cout << "Matrix product A = B*C; double; seed=42; 5 repeats\n"
         << "n      order    median seconds    check\n";
    mt19937 rng(42);
    uniform_int_distribution<int> value(-3, 3);
    for (int n : sizes)
    {
        Matrix b(n * n), c(n * n), reference(n * n, 0), a(n * n);
        for (double& x : b)
        {
            x = value(rng);
        }
        for (double& x : c)
        {
            x = value(rng);
        }
        multiply_ijk(reference, b, c, n);
        vector<vector<double>> times(6);
        // Rotate execution order to reduce systematic warm-up/thermal bias.
        for (int repeat = 0; repeat < 5; ++repeat)
        {
            for (int offset = 0; offset < 6; ++offset)
            {
                int index = (offset + repeat) % 6;
                fill(a.begin(), a.end(), 0.0);
                auto start = chrono::steady_clock::now();
                kernels[index](a, b, c, n);
                auto finish = chrono::steady_clock::now();
                double seconds = chrono::duration<double>(finish - start).count();
                if (a != reference)
                {
                    cerr << "Matrix mismatch: " << names[index] << '\n';
                    return 2;
                }
                double checksum = 0;
                for (double x : a)
                {
                    checksum += x;
                }
                times[index].push_back(seconds);
                csv << n << ',' << names[index] << ',' << repeat + 1 << ','
                    << seconds << ',' << checksum << '\n';
            }
        }
        for (int index = 0; index < 6; ++index)
        {
            sort(times[index].begin(), times[index].end());
            cout << left << setw(7) << n << setw(9) << names[index]
                 << fixed << setprecision(9) << times[index][2] << "    OK\n";
        }
        cout.flush();
    }
    cout << "All 6 orders match. Raw data: matrix_timings.csv\n";
    return 0;
}
