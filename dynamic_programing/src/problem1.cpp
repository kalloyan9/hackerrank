#include <iostream>
#include <vector>

struct MyPair {
    size_t buyIdx;
    size_t sellIdx;
};

/*
idx: 0   1   2   3   4   5   6   7   8
val: 5   4   3   6   7   2   8   1   9
ans: buy on idx 7 (val 1) and sell on idx 8 (val 9) -> profit = 8
*/
MyPair MaxProfit(const std::vector<int>& prices)
{
    if (prices.size() < 2)
    {
        return {0, 0};
    }

    size_t minIdxToBuy = 0;     // Tracks lowest price seen so far
    size_t bestBuyIdx = 0;      // Tracks buy index for the best profit found
    size_t bestIdxToSell = 1;   // Tracks sell index for the best profit found
    int bestProfit = prices[1] - prices[0];
    
    for (size_t i = 1; i < prices.size(); ++i)
    {
        int currentProfit = prices[i] - prices[minIdxToBuy];
        
        // Only update the winning pair when we find a strictly better profit
        if (currentProfit > bestProfit)
        {
            bestProfit = currentProfit;
            bestBuyIdx = minIdxToBuy;
            bestIdxToSell = i;
        }
        
        // Update running minimum for future iterations
        if (prices[i] < prices[minIdxToBuy])
        {
            minIdxToBuy = i;
        }
    }

    // Optional: If prices only ever decrease - do not buy
    if (bestProfit <= 0)
    {
        return {0, 0};
    }

    return {bestBuyIdx, bestIdxToSell};
}

int problem1_main()
{
    size_t days = 0;
    std::cin >> days;

    std::vector<int> prices;
    prices.reserve(days);
    
    int value = 0;
    for (size_t i = 0; i < days; ++i)
    {
        std::cin >> value;
        prices.push_back(value); // Fixed: actually add the element to the vector
    }

    MyPair answer = MaxProfit(prices);
    
    if (prices.size() < 2 || answer.buyIdx == answer.sellIdx)
    {
        std::cout << "No profitable trade (Profit: 0)" << std::endl;
    }
    else
    {
        int profit = prices[answer.sellIdx] - prices[answer.buyIdx];
        std::cout << "Buy on day " << answer.buyIdx 
                  << ", sell on day " << answer.sellIdx 
                  << " | Max Profit: " << profit << std::endl;
    }

    return 0;
}
