#include <iostream>
#include <vector>

struct MyPair {
    size_t buyIdx;
    size_t sellIdx;
};

/*
idx:0   1   2   3   4   5   6   7   8
val:5   4   3   6   7   2   8   1   9
ans: buy on 2 and sell on 4 idx
*/
MyPair MaxProfit(const std::vector<int>& prices)
{
    // Edge case: need at least 2 elements
    if (prices.size() < 2)
    {
        return {0, 0};
    }

    // Initialize tracking variables
    size_t minIdxToBuy = 0;
    int minValueToBuy = prices[0];
    
    size_t bestIdxToSell = 1;
    int bestProfit = prices[1] - prices[0];
    
    // Iterate through prices starting from index 1
    for (size_t i = 1; i < prices.size(); ++i)
    {
        // Calculate profit if we sell at current index after buying at minimum
        int currentProfit = prices[i] - minValueToBuy;
        
        // Update best profit and sell index if current profit is better
        if (currentProfit > bestProfit)
        {
            bestProfit = currentProfit;
            bestIdxToSell = i;
        }
        
        // Update minimum if current value is smaller
        if (prices[i] < minValueToBuy)
        {
            minValueToBuy = prices[i];
            minIdxToBuy = i;
        }
    }

    return {minIdxToBuy, bestIdxToSell};
}
// Time complexity: O(N), Space complexity: O(1)

int problem1_main()
{
    // init
    size_t days = 0;
    std::vector<int> prices;
    
    // input
    std::cin >> days;
    prices.reserve(days);
    int value = 0;
    for (int i = 0; i < days; ++i)
    {
        std::cin >> value;
    }

    // print
    MyPair answer = MaxProfit(prices);
    std::cout << answer.sellIdx - answer.buyIdx << std::endl;
    return 0;
}
