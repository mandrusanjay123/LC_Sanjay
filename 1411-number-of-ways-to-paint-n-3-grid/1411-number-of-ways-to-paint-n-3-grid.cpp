class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfWays(int n) {
        // vector<long long int> a(n,6),b(n,6);
        long long int a=6;
        long long int b=6;
        long long int curr_a=6;
        long long int curr_b=6;
        long long int tot = 0;
        for(int i=1;i<n;i++){
            curr_a = (2*a + 2*b) % mod;
            curr_b = (2*a + 3*b) % mod;
            a=curr_a;
            b=curr_b;
        }
        return (a + b) % mod;
    }
};