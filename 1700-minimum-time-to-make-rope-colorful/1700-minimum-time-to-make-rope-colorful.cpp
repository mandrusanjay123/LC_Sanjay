class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // if(colors.length()==1)return neededTime[0];
        int previousTime=0;
        vector<int>dp(colors.length()+1,0);
        char previousColor='A';
        for(int i=1;i<=colors.length();i++){
            if(previousColor==colors[i-1]){
                dp[i]=dp[i-1]+min(neededTime[i-1],previousTime);
                previousTime=max(previousTime,neededTime[i-1]);
                // previousColor=colors[i-1];
            }
            else{
                dp[i]=dp[i-1];
                previousTime=neededTime[i-1];
                previousColor=colors[i-1];
            }
        }
        return dp[colors.length()];
    }
};