#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> T(nums.size(), 0);
        vector<int> parent(nums.size(), 0);
        
        int m = 0;
        int mi = 0;
        
        // for(int i = 0; i < nums.size(); ++i) // if extending by larger elements
        for(int i = nums.size() - 1; i >= 0; --i) // iterate from end to start since it's easier to track the answer index
        {
            // for(int j = i; j >=0; --j) // if extending by larger elements
            for(int j = i; j < nums.size(); ++j)
            {
                // if(nums[i] % nums[j] == 0 && T[i] < 1 + T[j]) // if extending by larger elements
                // check every a[j] that is larger than a[i]
                if(nums[j] % nums[i] == 0 && T[i] < 1 + T[j])
                {
                    // if a[j] mod a[i] == 0, it means T[j] can form a larger subset by putting a[i] into T[j]
                    T[i] = 1 + T[j];
                    parent[i] = j;
                    
                    if(T[i] > m)
                    {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }
        
        vector<int> ret;
        
        for(int i = 0; i < m; ++i)
        {
            ret.push_back(nums[mi]);
            mi = parent[mi];
        }

      
        return ret;
    }
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
vector<int>nums;
fi(0,5){
    int x;
    cin>>x;
    nums.push_back(x);
}
auto ans = largestDivisibleSubset(nums);
fi(0,5)cout<<nums[i]<<" ";
return 0;
}
