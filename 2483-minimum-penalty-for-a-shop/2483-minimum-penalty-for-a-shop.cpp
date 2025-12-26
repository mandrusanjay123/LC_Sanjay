class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int currPenality=0;
        for(int c:customers){
            if(c=='Y')currPenality++;
        }
        int minPenality=n;
        int minId;
        int id;
        for(id=0;id<n;id++){
            if(currPenality<minPenality){
                minId=id;
                minPenality=currPenality;
            }
            if(customers[id]=='Y'){
                currPenality--;
            }
            else if(customers[id]=='N'){
                currPenality++;
            }
        }
        if(currPenality<minPenality)minId=id;
        return minId;
    }
};