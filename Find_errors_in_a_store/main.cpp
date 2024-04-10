#include <iostream>
#include <string>
#include <vector>
#include <map>

// #define DEV_TEST

static const float EPS = 0.001;

int findErrors(const std::vector<std::string>& products, const std::vector<float>& prices,
                const std::vector<std::string>& soldProducts, const std::vector<float>& soldPrices) {
    if (products.size() == prices.size() && soldProducts.size() == soldPrices.size()) {
        std::map<std::string, float> m;
        int errors = 0;
        for (int i = 0; i < products.size(); ++i) { 
            #ifdef DEV_TEST
                std::cout << "inserting: " << products[i] << ", " << prices[i] << std::endl;
            #endif
            m.insert(std::make_pair(products[i], prices[i]));
        }

        for (int i = 0; i < soldProducts.size(); ++i) {
            auto foundInMap = m.find(soldProducts[i]);
            if (foundInMap != m.end()) {
                if (std::abs(foundInMap->second - soldPrices[i]) > EPS) {
                    ++errors;
                }
                #ifdef DEV_TEST
                    std::cout << "searching for: " << soldProducts[i] << ", " << soldPrices[i] << std::endl;
                    std::cout << "found in map: " << foundInMap->first << ", " << foundInMap->second << std::endl;
                    std::cout << "errors = " << errors << std::endl; 
                #endif
            } else {
                std::cerr << "invalid input.\n";
                return -2;
            }
        }        
        return errors;
    } else {
        std::cerr << "invalid input.\n";
        
        #ifdef DEV_TEST
            std::cout << products.size() << " - ";
            for (auto it : products) std::cout << it << ", ";
            std::cout << std::endl;

            std::cout << prices.size() << " - ";
            for (auto it : prices) std::cout << it << ", ";
            std::cout << std::endl;

            std::cout << soldProducts.size() << " - ";
            for (auto it : soldProducts) std::cout << it << ", ";
            std::cout << std::endl;

            std::cout << soldPrices.size() << " - ";
            for (auto it : soldPrices) std::cout << it << ", ";
            std::cout << std::endl;
        #endif

        return -1;
    }
}

int main ()
{
    std::vector<std::string> products = {"apples", "cherries", "bannana", "rice"};
    std::vector<float> prices = {2.43, 6.50, 2.20, 8.60};

    std::vector<std::string> soldProducts = {"apples", "apples", "bannana", "cherries", "rice"};
    std::vector<float> soldPrices = {2.43, 2.81, 2.20, 6.50, 8.60};


    std::cout << findErrors(products, prices, soldProducts, soldPrices) << std::endl;

    return 0;
}