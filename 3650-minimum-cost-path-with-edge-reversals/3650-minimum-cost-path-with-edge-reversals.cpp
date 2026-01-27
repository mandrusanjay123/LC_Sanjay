class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});//for reversed weight
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;// pair for weight and then the node
        vector<int>dst(n,INT_MAX);//min dist for every node starting from 0
        // vector<bool>visited(n,false);

        pq.push({0,0});
        while(!pq.empty()){
            auto f=pq.top();
            pq.pop();
            int node=f.second;
            int dist=f.first;
            // visited[node]=true;
            if(dist>dst[node])continue;
            if(node==n-1){
                return dst[node];
            }
            for(auto neigh : adj[node]){
                int next_node = neigh.first;
                int dist_to_neigh = dist+neigh.second;
                if(dist_to_neigh<dst[next_node]){
                    dst[next_node]=dist_to_neigh;
                    pq.push({dist_to_neigh,next_node});
                }
            }
        }
        return -1;
    }
};