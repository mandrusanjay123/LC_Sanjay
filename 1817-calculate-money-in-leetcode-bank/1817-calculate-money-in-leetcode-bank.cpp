class Solution {
public:
    int totalMoney(int n) {
        int total_money=0;
        for(int i=1;i<=n;i++){
            if(i%7==0){
                total_money+=7+i/7-1;
                 cout<<7<<"+"<<i/7-1<<endl;
            }
            else{
            cout<<i%7<<"+"<<i/7<<endl;
            total_money+=i%7+i/7;
            }
        }
        return total_money;
    }
};