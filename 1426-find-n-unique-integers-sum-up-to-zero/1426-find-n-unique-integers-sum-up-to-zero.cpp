class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n==0){
            ans.push_back(0);
            return ans;
        }
        int cnt=1;
        while(cnt<n){
                ans.push_back(cnt);
                ans.push_back(-1*cnt);
                cnt+=2;
            }
        if(n%2!=0){
            ans.push_back(0);
        }
        return ans;
    }
};