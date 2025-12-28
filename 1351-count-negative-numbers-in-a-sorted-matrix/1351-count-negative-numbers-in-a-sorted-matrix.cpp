class Solution {
public:
    int bs(vector<int>nums,int left,int right){
        int n=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<0){
                right=mid-1;
            }
            else if(nums[mid]>=0){
                left=mid+1;
            }
        }
        // cout<<n-left<<endl;
        return (n-left)+1;

    }
    int countNegatives(vector<vector<int>>& grid) {
        //4 3 2 -1
        //3 2 1 -1
        //1 1 -1 -2
        //-1 -1 -2 -3
        int count=0;
        for(int i=0;i<grid.size();i++){
            count+=bs(grid[i],0,grid[i].size()-1);
        }
        return count;
    }
};