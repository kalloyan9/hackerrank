There is a store. The store has a list of products and their prices.
For some reason while selling the products the cashier made errors.
The store want to count all the errors made by the cashier.

The inputs are 4 vectors:
products – containing the products (can not have duplicates), 
prices – containing the real and expected price of each product,
sold products – containing the sold products from the cashier (can have duplicates – one product can be sold more than 1 time),
sold products prices – containing the prices that the cashier sold each product for.

It’s guaranteed that the count of the products equals the count of the prices.
And it’s guaranteed that the count of the sold products equals the count of the sold product prices.

Example:
input:
“apples", "cherries", "bannana", "rice"
2.43, 6.50, 2.20, 8.60
"apples", "apples", "bannana", "cherries", "rice"
2.43, 2.81, 2.20, 6.50, 8.60

output:
1

implement only a function with this syntax:
findErrors(const std::vector<std::string>& products, const std::vector<float>& prices,
const std::vector<std::string>& soldProducts, const std::vector<float>& soldPrices)
the input will be held in the main method.
