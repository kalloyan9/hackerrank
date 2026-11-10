#include <iostream>
#include <limits>

#include "StartAndMeasureThread.hpp"

static const long long MOD = 1'000'000'007, FIB0 = 0, FIB1 = 1, N = 20;

long long fib_rec_helper(size_t n, long long prev2, long long prev1)
{
    if (n == 0)
        return prev2;
    if (n == 1)
        return prev1;

    // overflowing
    if (prev1 > std::numeric_limits<long long>::max() - prev2)
        return -1;

    return fib_rec_helper(n - 1, prev1, prev2 + prev1);
}

long long fib_rec(size_t n)
{
    long long res = 0;
    res = fib_rec_helper(n, FIB0, FIB1);
    return res;
}

long long fib_it(size_t n)
{
    long long currentFib = FIB0, prev1 = FIB0, prev2 = FIB1;
    for (size_t i = 1; i <= n; ++i)
    {
        // overflowing
        if (prev1 > std::numeric_limits<long long>::max() - prev2)
            return -1;
        currentFib = prev1 + prev2;
        prev2 = prev1;
        prev1 = currentFib;
    }

    return currentFib;
}

int problem3_main()
{
    using namespace std::chrono;

    long long res_rec = 0, res_it = 0;
    long long time_rec = 0, time_it = 0;

    res_rec = start_and_measure("t_rec", fib_rec, N);
    res_it  = start_and_measure("t_it",  fib_it,  N);

    std::cout << "Matching: " << ((res_it == res_rec) ? "yes" : "no") << std::endl;

    return 0;
}
