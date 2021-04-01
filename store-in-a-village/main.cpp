#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// types
#define EMPTY 0
#define HOUSE -1
using typecoords = pair<int, int>;

// GLOBALS
int n, m, k, d;
int **matrix = nullptr;
const typecoords dummy(-1, -1); // used for counting the range in step varriable
vector<typecoords> houses;
vector<typecoords> answers;


void print()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[j][i] == HOUSE)
                cout << 'H' << '\t';
            else 
                cout << matrix[j][i] << '\t';
        }
        cout << endl << endl << endl << endl;
    }
    cout << "\n==============================================\n";
}

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

void bfs(typecoords house, unordered_map<typecoords, bool, hash_pair>& used)
{
    queue<typecoords> q;
    int step = 0;
    // left
    if (house.first - 1 >= 0 && matrix[house.first - 1][house.second] != HOUSE) {
        used[make_pair(house.first - 1, house.second)] = true;
        q.push(make_pair(house.first - 1, house.second));
    }
    // right
    if (house.first + 1 < n && matrix[house.first + 1][house.second] != HOUSE) {
        used[make_pair(house.first + 1, house.second)] = true;
        q.push(make_pair(house.first + 1, house.second));
    }
    // up
    if (house.second - 1 >= 0 && matrix[house.first][house.second - 1] != HOUSE) {
        used[make_pair(house.first, house.second - 1)] = true;
        q.push(make_pair(house.first, house.second - 1));
    }
    // down
    if (house.second + 1 < m && matrix[house.first][house.second + 1] != HOUSE) {
        used[make_pair(house.first, house.second + 1)] = true;
        q.push(make_pair(house.first, house.second + 1));
    }
    // dummy
    q.push(dummy);

    while (!q.empty()) {
        typecoords curr = q.front();
        q.pop();
        if (curr == dummy) {
            step++;
            if (step + 1 > d)
                break;
            else {
                q.push(dummy);
                continue;
            }
        }

        // increase number of paths and add answer if needed
        matrix[curr.first][curr.second]++;
        if (matrix[curr.first][curr.second] >= k)
            answers.push_back(curr);

        // childs
        typecoords next = curr; // helper
        // left
        next.first = curr.first - 1;
        auto it = used.find(next);
        if (next.first >= 0 && it == used.end() && matrix[next.first][next.second] != HOUSE) {
            q.push(next);
            used[next] = true;
        }
        // right
        next.first = curr.first + 1;
        it = used.find(next);
        if (next.first < n && it == used.end() && matrix[next.first][next.second] != HOUSE) {
            q.push(next);
            used[next] = true;
        }
        // up
        next.first = curr.first;
        next.second = curr.second - 1;
        it = used.find(next);
        if (next.second >= 0 && it == used.end() && matrix[next.first][next.second] != HOUSE) {
            q.push(next);
            used[next] = true;
        }
        // down
        next.second = curr.second + 1;
        it = used.find(next);
        if (next.second < m && it == used.end() && matrix[next.first][next.second] != HOUSE) {
            q.push(next);
            used[next] = true;
        }
    }
}

void solve()
{
        unordered_map<typecoords, bool, hash_pair> used;
        for (auto it : houses) {
            bfs(it, used);
            used.clear();
        }
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
                cout << "input " << i << "-th house coordinates: " << endl;
                cin >> x >> y;
                matrix[x][y] = HOUSE;
                houses.push_back(make_pair(x, y));
        }
        cout << "input D: " << endl;
        cin >> d;
        
        // calculating
        print();
        solve();
        for (int i = 0; i < n; ++i)
            delete[] matrix[i];
        delete[] matrix;
        print();

        // output
        cout << "\n==============================================\n";
        cout << "all possible places for a store in a village are: " << answers.size() << endl;
        for (auto it : answers) 
                cout << '(' << it.first << ',' << it.second << ')' << endl;

        return 0;
}

/*
input:

5 5
3
1 0
1 2
2 3
2

output:
1 -> (2, 1);
*/