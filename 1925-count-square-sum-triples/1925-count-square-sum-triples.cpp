class Solution {
public:
    int countTriples(int n) {
        int count=0;
         for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(k>=j&&j>=i){
                        if(i*i+j*j==k*k)count++;
                    }
                }
            }
         }
         return 2*count;
    }
};