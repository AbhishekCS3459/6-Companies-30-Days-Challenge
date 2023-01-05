#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
vector<int>nums;
fi(0,5){
    int x;
    cin>>x;
    nums.push_back(x);
}
cout<<maxRotateFunction(nums)<<" ";
return 0;
}
 int maxRotateFunction(vector<int>& nums) {
        int sum =0;
        int f=0;
        for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			f+=i*nums[i];
		}
        
        int globalSum = f;
        
        for(int i=nums.size()-1;i>0;i--){
            f = f + sum -nums.size()*nums[i];
            globalSum = max(f,globalSum);
        }
        return globalSum;
    }