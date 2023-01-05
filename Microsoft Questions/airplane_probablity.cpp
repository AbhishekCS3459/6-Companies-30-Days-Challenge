#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

return 0;
}
 double nthPersonGetsNthSeat(int n)
    {
        vector<double> dp(n);       //dp(5)=dp(1)/5  +  dp(2)/5  +  dp(3)/5  +  dp(4)/5;
        dp[0]=1;
        double sum=1;
        for(double i=1;i<n;i++)
        {
            dp[i]=sum/(i+1.0);
            sum+=dp[i];
        }
        return dp[n-1];
    }