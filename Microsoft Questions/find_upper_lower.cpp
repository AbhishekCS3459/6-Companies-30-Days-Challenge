#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
const int N = 1e5;

vector<bool> is_prime(N, 1);
vector<int>Lp,Up;
pair<int,int> upper_lower_prime(int n)
{
    is_prime[0] = is_prime[1] = false;
    // now we start form 2 and mark all the muktiples of 2 to false
    for (int i = 2; i < N; i++)
    {
        int j = 2 * i;
        if (is_prime[i] == true)
            while (j < N)
            {
                is_prime[j] = false;
                // Upper bound

                j = j + i;
            }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
string s;
cin>>s;

s.erase();
cout<<s;
    return 0;
}
