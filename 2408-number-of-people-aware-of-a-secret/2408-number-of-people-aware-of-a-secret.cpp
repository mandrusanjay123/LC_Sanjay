class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long mod= 1'000'000'007;
        if(n==0)return n;
        vector<int>add(n+1,0);// no of active gossipers on day n;
        long long aware=1;
        long long shareable;
        add[1]=1;
        for(int day=2;day<=n;day++){
            if(day-delay>=1){
                shareable+=add[day-delay];
                 if(shareable>=mod){
                shareable-=mod;
            }
            }
            if(day-forget>=1){
                shareable-=add[day-forget];
                 if(shareable<0){
                shareable+=mod;
            }
            }
           
           
            add[day]=shareable;
            aware+=add[day];
             if(aware>=mod){
                aware-=mod;
            }
            if(day-forget>=1){
                aware-=add[day-forget];
                if(aware<mod)aware+=mod;
            }    
            
                }
                return (aware%mod);

    }
};