class Solution {
public:
    // int ans;
    int findDivisor(int n){
        int sum=0;
        int count=0;
        // for(int i=1;i*i<=num;i++){
        //     if(num%i==0){
        //         count++;
        //         sum+=i;
        //     }
        // }
         for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
             count++;
             sum+=i;
            // If the other divisor (n/i) is different from 'i', add it as well
            if (i * i != n) {
                // divisors.push_back(n / i);
                sum+=n/i;
                count++;
            }
        }
    }
        // cout<<sum<<endl;
        return (count==4)?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            // ans=0;
            sum+=findDivisor(nums[i]);
        }
        return sum;
    }
};