#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    const int ALPHABET_SIZE = 26;
    int count1[ALPHABET_SIZE] = {0};
    int count2[ALPHABET_SIZE] = {0};
    
    for (int i = 0; a[i] != '\0'; ++i)
        count1[a[i] - 'a']++;
    for (int i = 0; b[i] != '\0'; ++i)
        count2[b[i] - 'a']++;

    int res = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        res += abs(count1[i] - count2[i]);
        
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

