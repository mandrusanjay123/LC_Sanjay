class Solution {
public:
bool check(vector<int>&temp){
    for(int i=0;i<temp.size();i++){
        if(temp[i]!=0)return false;
    }
    return true;
}
void go(vector<int>&temp,bool left,int i){
    while(i>=0&&i<temp.size()){
    if(left){//going left
        if(temp[i]>0){
            temp[i]--;
            i++;
            left=false;
        }
        else {
            i--;
        }
    }
    else{//going right
    if(temp[i]>0){
        temp[i]--;
        i--;
        left=true;
    }
    else{
        i++;
    }
    }
}
    return;
}
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int curr=0;curr<nums.size();curr++){
            if(nums[curr]==0){
                //go left
                // int i=curr;
                vector<int>temp=nums;
                bool left=true;
               go(temp,left,curr);
            //    for(int i=0;i<temp.size();i++)cout<<temp[i]<<",";
               cout<<endl;
               if(check(temp)){
                    ans++;
                }
                //go right
                temp=nums;
                // i=curr;
                left=false;
                go(temp,left,curr);
                if(check(temp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};