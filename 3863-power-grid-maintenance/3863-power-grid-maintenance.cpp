class DSU{   
    vector<int>root;
    vector<int>rank;
    public:
        DSU(int n):root(n+1),rank(n+1,-1){
            iota(root.begin(),root.end(),0);
        }
        int find(int x){
            if(x==root[x])return x;
            return root[x]=find(root[x]);
        }
        bool Union(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b)return 0;
            if(rank[a]>rank[b]){
                root[b]=a;
                rank[a]++;
            }
            else if(rank[a]<rank[b]){
                root[a]=b;
                rank[b]++;
            }
            else{
                rank[a]++;
                root[b]=a;
            }
            return 1;
        }
    };
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU g(c);
        for(auto & c:connections){
            g.Union(c[0],c[1]);
        }
        vector<set<int>>comp(c+1);
        for(int i=1;i<=c;i++){
            comp[g.find(i)].insert(i);
        }
        vector<int>ans;
        for(auto &q:queries){
            int t=q[0];
            int x=q[1];
            int root_x=g.find(x);
            auto &C=comp[root_x];
            if(t==2){
                C.erase(x);
            }
            else{
                if(C.empty()){
                    ans.push_back(-1);
                }
                else if(C.count(x)){
                    ans.push_back(x);
                }
                else{
                    ans.push_back(*C.begin());
                }
            }
        }
        return ans;
    }
};