#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
  int numberOfSubstrings(string s) 
  {
    int i = 0 , j = 0 ;
   
    map<char,int>m;
    //map 

    int len = s.size() - 1;
    
    int cnt = 0; //to store answer

    while(j!=s.size()) //while 'j' reaches the last index
    {
        m[s[j]]+=1; //count frequency of each character for each 'j' index

        while(m['a'] and m['b'] and m['c']) // when an index 'l' and 'j' has come such that 'a','b','c' all 3 exists in map
        {
            cnt+=1 + (len-j); // count all substrings that can be formed till 'r'
            
            m[s[i]]-=1; //shrink window size by reducing the frequency of 'lth' character
            
            i++; //increment 'l' to go to next window
        }
        j++; //increment 'j' 
    }

    return cnt;
  }
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);
string s;
cin>>s;
cout<<numberOfSubstrings(s);
return 0;
}
