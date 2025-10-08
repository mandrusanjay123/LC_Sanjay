class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int m=spells.size();
        int n=potions.size();
        sort(potions.begin(),potions.end());
        // sort(spells.begin(),spells.end());
        for(int i=0;i<m;i++){
            if(1LL*spells[i]*potions[n-1]<success){
                ans.push_back(0);
                continue;
            }
            if(1LL*spells[i]*potions[0]>=success){
                ans.push_back(n);
            }
            else{
                int left=0;
                int right=n-1;
                int mid=0;
                while(left<right){
                    mid=left+(right-left)/2;
                    if(1LL*spells[i]*potions[mid]<1LL*success){
                        left=mid+1;
                    }
                    else{
                        right=mid;
                    }
                }
                ans.push_back(n-left);
            }
        }
        return ans;
    }
};