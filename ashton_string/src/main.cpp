#include <bits/stdc++.h>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
#define _TESTING

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'ashtonString' function below.
 *
 * The function is expected to return a CHARACTER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
char ashtonStringBruteForce(const string& s, int k)
{
    set<string> dic;
    
    // Generate all substrings
    for (size_t i = 0; i < s.length(); ++i) {
        for (size_t len = 1; len <= s.length() - i; ++len) {
            dic.insert(s.substr(i, len));
        }
    }

    string finalStr = "";
    for (const string& sub : dic) {
        finalStr += sub;
    }

    #ifdef _TESTING
    cout << finalStr << endl;
    #endif //_TESTING

    // counting from 1 to N
    return finalStr[k - 1];
}

#ifdef _TESTING
int main()
{
    {
        // test 1
        string input = "dbac";
        int k = 3;
        cout << ashtonStringBruteForce(input, k) << endl;
        return 0;
    }

    {
        // test 2
        string input = "ab";
        int k = 2;
        cout << ashtonStringBruteForce(input, k) << endl;
    }

    {
        // test 3
        string input = "cba";
        int k = 4;
        cout << ashtonStringBruteForce(input, k) << endl;
    }

    return 0;
}
#else
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        char res = ashtonString(s, k);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
#endif //_TESTING