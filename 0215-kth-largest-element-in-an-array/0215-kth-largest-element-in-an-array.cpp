class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int n=nums.size();
       for(int num:nums){
        if(pq.size()<k){
            pq.push(num);
        }
        else if(pq.top()<num){
            pq.pop();
            pq.push(num);
        }
       }
    //    while(!pq.empty()){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    //    }
       return pq.top();
    }
};