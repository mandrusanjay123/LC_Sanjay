class Solution {
public:
    int countCollisions(string directions) {
        int block=0;
        int right=0;
        int collisions=0;
        for(int i=0;i<directions.size();i++){
            if(directions[i]=='R'){
                right++;
            }
            else if(directions[i]=='L'){
                if(right>0){
                    collisions+=(right+1);
                    right=0;
                    block++;
                }
                else if(block>0){
                    collisions++;
                    block++;
                }
            }
            else{
                block++;
                collisions+=right;
                right=0;
            }
        }
        return collisions;
    }
};