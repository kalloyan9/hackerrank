TASK 1: STOCK MARKET (SHARES)

---

Description:
You have access to historical data for a company's stock prices over N consecutive days.
The stock price on day i is a positive integer P_i.

You have enough money to buy exactly one share.
You can buy the share on a chosen day X and you must sell it on some subsequent day Y (X < Y).
Your profit from this transaction will be P_Y - P_X.

Write a program that finds the maximum possible profit you can make.
If the stock market only goes down and no positive profit is possible
(i.e., every purchase results in a loss),
the program should output 0 (in which case it is best not to buy anything).

Input:
The first line of the standard input contains an integer N (1 <= N <= 100 000) – the number of days.
The second line contains N positive integers P_1, P_2, ..., P_N (1 <= P_i <= 1 000 000 000) –
the stock prices on the respective days, separated by a space.

Output:
On the standard output, print a single integer – the maximum possible profit.

Example:
Input:
6
7 1 5 3 6 4

Output:
5

Explanation: We buy on day 2 (price 1) and sell on day 5 (price 6). Profit = 6 - 1 = 5.

TASK 2: FROG (JUMPING STONES WITH K STEPS)

---

Description:
In a swamp, there is a sequence of N stones, numbered from 1 to N. On each stone, 
there is an integer A_i written (which can be positive, negative, or zero).
This number indicates how many points a frog earns (or loses) if it lands on this stone.

The frog starts its journey from stone number 1 and must reach stone number N.
From each stone, the frog can jump forward from 1 to K steps
(i.e., from stone i, it can jump to stones i+1, i+2, ..., i+K).

Upon landing on any stone (including the starting and ending ones),
the number written on the stone is added to the frog's total points.
Write a program that finds the maximum possible sum of points
the frog can collect on its way from the first to the last stone.

Input:
The first line contains two integers N and K (2 <= N <= 100 000, 1 <= K <= 100 000) –
the number of stones and the maximum jump size.
The second line contains N integers A_1, A_2, ..., A_N (-10 000 <= A_i <= 10 000) –
the points on the respective stones.

Output:
Print a single integer – the maximum number of points with which the frog can finish.

Example 1:
Input:
5 3
0 -3 5 -2 4

Output:
9

Explanation: The frog jumps from stone 1 directly to stone 3 (+5 points),
then directly to stone 5 (+4 points). Total: 0 + 5 + 4 = 9.
Since K=3, the jump from stone 1 to 3 (length 2) and from 3 to 5 (length 2) is allowed.

Example 2:
Input:
7 2
0 -1 -2 -3 -4 -5 0

Output:
-6

Explanation: We can jump at most 2 steps, so we go through: 1 -> 3 -> 5 -> 7. 
Points: 0 - 2 - 4 + 0 = -6.

TASK 3: RABBIT POPULATION

---

Description:
At the beginning of the first month, a newborn pair of rabbits is brought to a farm.
Rabbits grow quickly and reach sexual maturity at the age of one month.

The breeding rules are as follows:

* Every pair of rabbits that is 2 months old or older gives birth to exactly one new pair of rabbits every month.
* Rabbits never die.

Write a program that calculates the total number of rabbit pairs that will be on the farm at the end of the N-th month.

Input:
The single line contains an integer N (1 <= N <= 42) – the number of months.

Output:
Print a single integer – the number of rabbit pairs.

Example:
Input:
5

Output:
5