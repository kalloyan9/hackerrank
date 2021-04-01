#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


#define EMPTY 0
#define HOUSE -1

// GLOBALS
int n, m, k, d;
int **matrix = nullptr;
pair<int,int> dummy(-1, -1); // used for counting range in step varriable
vector<pair<int, int>> houses;
vector<pair<int, int>> answers;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void bfs(pair<int, int> p)
{
        unordered_map<pair<int,int>, bool, hash_pair> used;
        queue<pair<int, int>> q;
        
        if (p.first - 1) // left
                q.push(make_pair(p.first - 1, p.second));
        if (p.first + 1 < n) // right
                q.push(make_pair(p.first + 1, p.second));
        if (p.second - 1) // down
                q.push(make_pair(p.first, p.second - 1));
        if (p.second + 1 < m) // up
                q.push(make_pair(p.first, p.second + 1));
        q.push(dummy);
        int step = 1;
        
        while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                if (curr == dummy)
                        ++step;
                if (step > d)
                        break;

                auto it = used.find(curr);
                if (matrix[curr.first][curr.second] != HOUSE && it == used.end()) { // valid and unused coordinates
                        ++matrix[curr.first][curr.second];
                        if (matrix[curr.first][curr.second] >= k)
                                answers.push_back(curr);
                        used[curr] = true;

                        pair<int, int> next = curr;
                        // left
                        next.first = curr.first - 1;
                        it = used.find(next);
                        if (next.first && it == used.end())
                                q.push(next);
                        // right
                        next.first = curr.first + 1;
                        it = used.find(next);
                        if (next.first < n && it == used.end())
                                q.push(next);
                        // down
                        next.first = curr.first;
                        next.second = curr.second - 1;
                        it = used.find(next);
                        if (next.second && it == used.end())
                                q.push(next);
                        // right
                        next.second = curr.second + 1;
                        it = used.find(next);
                        if (next.second < m && it == used.end())
                                q.push(next);

                }
        }
}

void solve()
{
        for (auto it : houses)
                bfs(it);
}

int main ()
{
        // input
        cout << "input N and M:" << endl;
        cin >> n >> m;
        matrix = new int*[n];
        for (int i = 0; i < n; ++i)
                matrix[i] = new int[m](); // initialize with zeroes
        cout << "input K:" << endl;
        cin >> k;
        int x, y;
        houses.reserve(k);
        for (int i = 1; i <= k; ++i) { // initialize K houses
                cout << "input " << k << "-th house coordinates: " << endl;
                cin >> x >> y;
                matrix[x][y] = HOUSE;
                houses.push_back(make_pair(x, y));
        }
        cout << "input D: " << endl;
        cin >> d;
        
        // calculating
        solve();

        // output
        cout << "\n==============================================\n";
        cout << "all possible places for a store in a village are: " << answers.size() << endl;
        for (auto it : answers) 
                cout << '(' << it.first << ',' << it.second << ')' << endl;

        return 0;
}

/*
4 4
3
1 0
1 2
2 3
2
*/