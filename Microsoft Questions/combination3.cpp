// leet code --> question 216 same as leet code 39
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
void find_combination(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds, int idx, int k)
{
    
    if (idx == candidates.size())
    {
        if (target == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        else
            return;
    }
    if (target >= candidates[idx])
    {
        ds.push_back(candidates[idx]);
        find_combination(candidates, target - candidates[idx], ans, ds, idx + 1, k);
        ds.pop_back();
    }
    find_combination(candidates, target, ans, ds, idx + 1, k);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> candidates;
    for (int i = 1; i <= 9; i++)
        candidates.push_back(i);
    vector<vector<int>> ans;
    vector<int> ds;
    int idx = 0;
    find_combination(candidates, n, ans, ds, idx, k);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
