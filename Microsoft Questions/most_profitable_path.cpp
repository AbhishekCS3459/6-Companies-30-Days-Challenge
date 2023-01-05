#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi(a,n) for(int i=a;i<n;i++)
int main(){
 ios_base::sync_with_stdio(false);
  cin.tie(NULL);

return 0;
}
    vector<int> parent; 
    vector<vector<int>> graph;
    vector<bool> vis;
    int ans = INT_MIN; //value that has to be maximized before returning
	
    void solve(int src,int par){ //setting parent of each node
        parent[src] = par;
        for(auto itr:graph[src]){
            if(itr!=parent[src]) solve(itr,src);
        }
    }
	
    void solve2(int src,int end,vector<int>&amt,int sum){
        int sum2 = sum;
        if(vis[src]==false){ //visiting node for the first time
            vis[src] = true;
            if(src==end){ //If Alice and Bob are on the same nod
                sum2+= amt[src]/2;
            }
            else sum2+= amt[src];
        }
        for(auto itr:graph[src]){
            if(itr!=parent[src]){ //Alice has to move down towards the leaf node
                int res =  -1;
                if(end!=-1){
                    res = parent[end]; //Bob has to move upwards towards src node 0
					//Note that there is always only one unique path for Bob
                    vis[end] = true; //marking node where Bob stands as true
                }
                solve2(itr,res,amt,sum2); 
                if(end!=-1) vis[end] = false;
            }
        }
        if(graph[src].size()<=1 && parent[src]!=-1) ans = max(ans,sum2); //Leaf node case where ans value needs to be checked and maximized
        vis[src] = false;
    }
	
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        parent.resize(100001,-1);  
        graph.resize(edges.size()+1);
        for(int i=0;i<edges.size();i++){ //constructing graph from edges vector
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        solve(0,-1); //function to set parent of each node 
		//Note that parent of src node 0 is set to -1
		
        vis.resize(100001,false); //boolean vector vis to keep track of all visited nodes
        solve2(0,bob,amount,0);
        return ans;
    }