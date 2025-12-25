class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long decrement=0;
        long long total=0;
        int i=0;
        int n=happiness.size();
        while(k--&&i<n){
                total+=(happiness[i]-decrement)>=0?(happiness[i]-decrement):0;
                decrement++;
                i++;
        }
        return total;
    }
};