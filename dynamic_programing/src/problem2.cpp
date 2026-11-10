#include <iostream>
#include <vector>

// dp with memoization
int solve_dp(std::vector<int> &values, size_t k)
{
    int n = values.size();
    if (n == 0) return 0;
    if (n == 1) return values[0];

    std::vector<int> mem(k, INT_MIN);
    mem[0] = values[0];

    for (int i = 1; i < n; ++i)
    {
        int max_prev = INT_MIN;
        for (int step = 1; step <= k; ++step)
        {
            if (i - step >= 0)
            {
                max_prev = std::max(max_prev, mem[(i - step) % k]);
            }
        }
        mem[i % k] = max_prev + values[i];
    }

    return mem[(n - 1) % k];
}

// standart problem with k = 2 - O(n) computing + O(1) memory
int solve_dp_step2(const std::vector<int> &values)
{
    int n = values.size();
    
    if (n == 0) return 0;
    if (n == 1) return values[0];

    int prev2 = values[0];
    int prev1 = values[0] + values[1];

    for (int i = 2; i < n; ++i)
    {
        int current = std::max(prev1, prev2) + values[i];
        
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int problem2_main()
{
    // init
    size_t n = 0, k = 0;
    std::vector<int> values;
    
    // input
    std::cin >> n;
    std::cin >> k;
    values.reserve(n);
    int value;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        values.push_back(value);
    }

    // solve
    int answer = solve_dp(values, k);

    // print
    std::cout << answer << std::endl;
    return 0;
}