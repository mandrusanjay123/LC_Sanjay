class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //not greedy
        //dp-->knapsack
        sort(events.begin(),events.end());
        vector<int>maxSufix(events.size(),0);
        int n=events.size();
        maxSufix[n-1]=events[n-1][2];
        int sum=0;
        for(int i=events.size()-2;i>=0;i--){
            maxSufix[i]=max(maxSufix[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0;i<events.size();i++){
            int curVal=events[i][2];
            ans=max(ans,curVal);
            int nextStart=events[i][1]+1;
            int low=i+1;
            int high=n-1;
            int idx=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(events[mid][0]>=nextStart){
                    idx=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(idx!=-1){
                ans=max(ans,curVal+maxSufix[idx]);
            }
        }
        return ans;
    }
};