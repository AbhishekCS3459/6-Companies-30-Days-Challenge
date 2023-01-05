#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
string s,g;
cin>>s>>g;
cout<<getHint(s,g);
    return 0;
}
string getHint(string s, string g)
{
    // support variables
    int bulls = 0, cows = 0, len = s.size();
    string res;
    // checking the numbers of cows
    char freqs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (char c : s)
        freqs[c - '0']++;
    for (char c : g)
    {
        c -= '0';
        // every time we find a match, we decrease it in freqs and increase cows
        if (freqs[c])
        {
            freqs[c]--;
            cows++;
        }
    }
    // checking for the number of bulls
    for (int i = 0; i < len; i++)
        if (s[i] == g[i])
            bulls++;
    // adjusting cows
    cows -= bulls;
    // composing the final result
    res = to_string(bulls) + 'A' + to_string(cows) + 'B';
    return res;
}