class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_area=0;
        while(left<=right){
            int h=min(height[left],height[right]);
            max_area=max(max_area,h*(right-left));
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return max_area;
    }
};