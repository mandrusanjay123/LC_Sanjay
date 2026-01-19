class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())return "";
        string ans="";
        int l=0;
      
        auto &v=mp[key];
        int r=v.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid].first<=timestamp){
                l=mid+1;
                ans=v[mid].second;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */