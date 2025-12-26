class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int activeCustomers=0;
        for(int c:customers){
            if(c=='Y')activeCustomers++;
        }
        int minPenality=n;
        int currPenality=activeCustomers;
        int minId=INT_MAX;
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