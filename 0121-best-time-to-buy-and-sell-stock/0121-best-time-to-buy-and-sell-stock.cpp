class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_sell=0;
        int min_cost=INT_MAX;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(min_cost>prices[i]){
                min_cost=prices[i];
                max_sell=prices[i];
            }
            max_sell=max(max_sell,prices[i]);
            max_profit=max(max_profit,max_sell-min_cost);
        }
        return max_profit;
    }
};