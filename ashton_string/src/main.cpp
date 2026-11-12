#include <bits/stdc++.h>
#include <string>
#include <set>

using namespace std;

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
#define _TESTING

char ashtonString(string s, int k) {
    set<string> dic{};
    const char *pS = s.c_str(), *pIt = nullptr;
    // iterate the string by steps ([1...size] words) and put all possibilities to the set.
    // set is sorted, so the lexicographic order will be guaranteed
    for (int step = 1; step <= s.size(); ++step)
    {
        pS = s.c_str();
        string subStr{*pS};
        for (pS = s.c_str(); *pS != '\0'; ++pS)
        {
            // terminate if the next one is the end
            if (*(pS + 1) == '\0')  continue;

            subStr = *pS;
            size_t len = 1;
            // otherwise extract substring
            for (pIt = pS + 1; *pIt != '\0' && len < step; ++pIt, ++len)
            {
                subStr.push_back(*pIt);
            }
            dic.insert(subStr);
        }
    }

    for (auto it : dic)
    {
        cout << it << ",";
    }
    return 0;
}

#ifdef _TESTING
int main()
{
    string input = "dbac";
    int k = 3;
    ashtonString(input, k);
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