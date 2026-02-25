class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        vector<pair<int,int>>store;
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            int num_bits=0;
            while(num>0){
                num_bits+=(num&1);
                num>>=1;
            }
            store.push_back({num_bits,arr[i]});
        }
        sort(store.begin(),store.end(),[](const pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        });
        for(int i=0;i<store.size();i++){
            ans.push_back(store[i].second);
        }
        return ans;
    }
};