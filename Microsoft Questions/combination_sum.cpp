#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a, n) for (int i = a; i < n; i++)
void find_combination(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &ds, int idx)
{
    // base case whien we cover all the elements
    if (idx == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        else
            return;
    }
    // include a number
    if (target >= candidates[idx])
    {
        ds.push_back(candidates[idx]);
        find_combination(candidates, target - candidates[idx], ans, ds, idx);
        ds.pop_back();
    }
    find_combination(candidates, target, ans, ds, idx + 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int idx = 0;
    find_combination(candidates, target, ans, ds, idx);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>candidt;
    int target = 5;
    fi(0,5){
        int x;
        cin>>x;
        candidt.push_back(x);
    }
    auto ans = combinationSum(candidt,target);
    for(auto in:ans){
        for(auto ele:in){
            cout<<ele<<" ";
        }
        cout<<endl;
    }


    return 0;
}
