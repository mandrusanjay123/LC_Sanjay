class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int num_primebits=0;
        for(int i=left;i<=right;i++){
            // int i=6;
            int num=0;
            int n=i;
            while(n>0){
                num+=(n%2==0)?0:1;
                n>>=1;
            }
            // cout<<num<<endl;
            bool isprime=true;
            if (num >= 2) {
                for (int i = 2; i <= std::sqrt(num); ++i) {
                    if (num % i == 0) {
                        isprime=false; 
                        }
                }
            }
            else{
                isprime=false;
            }
            if(isprime)num_primebits++;
        }
        return num_primebits;
    }
};