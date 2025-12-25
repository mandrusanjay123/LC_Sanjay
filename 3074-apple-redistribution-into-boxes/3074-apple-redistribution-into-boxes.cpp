class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int sum=0;
        for(int a:apple)sum+=a;
        int id=0;
        for(int c:capacity){
            id++;
            sum-=c;
            if(sum<=0)break;
        }
        return id;
    }
};