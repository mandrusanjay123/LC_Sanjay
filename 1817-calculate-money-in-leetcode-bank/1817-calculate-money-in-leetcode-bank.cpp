class Solution {
public:
    int totalMoney(int n) {
        int total_money=0;
        for(int i=1;i<=n;i++){
            if(i%7==0){
                total_money+=7+i/7-1;
            }
            else{
            total_money+=i%7+i/7;
            }
        }
        return total_money;
    }
};