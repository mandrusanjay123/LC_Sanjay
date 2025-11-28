class Solution {
public:
int components=0;
long long dfs(int u,int parent,vector<vector<int>>&adj,vector<int>&values,int k){
    long long sum=values[u];
    for(int neigh:adj[u]){
        if(neigh==parent)continue;
        // 
        sum+=dfs(neigh,u,adj,values,k);
        
    }
    if(sum%k==0){
        components++;
        return 0;
    }
    else{
        return sum;
    }
    return 0;
}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0,-1,adj,values,k);
        return components;
    }
};