#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // LeetCode guarantees denominator != 0
        if (numerator == 0) return "0";

        string res;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) res.push_back('-');

        // Use 64-bit to avoid overflow on abs(INT_MIN)
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;          // no fractional part

        res.push_back('.');

        // remainder -> position in result string where the digit from this remainder was placed
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                int idx = seen[rem];
                res.insert(idx, "(");
                res.push_back(')');
                break;
            }
            seen[rem] = (int)res.size();

            rem *= 10;
            res.push_back(char('0' + (rem / d)));
            rem %= d;
        }

        return res;
    }
};
