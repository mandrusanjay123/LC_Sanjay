class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(string s:operations){
            for(char c:s){
                if(c=='-'){
                    ans--;
                }
                else if(c=='+'){
                    ans++;
                }
                else continue;
                break;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};