class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int activeCustomers=0;
        for(int c:customers){
            if(c=='Y')activeCustomers++;
        }
        //YNNNNNN
        if(activeCustomers==n)return n;
        if(activeCustomers==0)return 0;
        int minPenality=n;
        int currPenality=activeCustomers;
        int minId=INT_MAX;
        cout<<minPenality<<endl;
        cout<<0<<","<<currPenality<<endl;
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
          
            cout<<id+1<<","<<currPenality<<endl;
        }
        if(currPenality<minPenality)minId=id;
        return minId;
    }
};