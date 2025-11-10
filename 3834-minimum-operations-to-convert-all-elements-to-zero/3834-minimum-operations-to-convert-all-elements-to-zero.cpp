class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        st.push(0);                 // sentinel 0

        for (int num : nums) {
            // Pop all layers that are higher than current num
            while (!st.empty() && st.top() > num) {
                st.pop();
            }

            // If num starts a new positive layer
            if ((st.empty() || st.top() < num) && num > 0) {
                ++ans;
                st.push(num);
            }
            // if st.top() == num or num == 0 with top==0, do nothing
        }

        return ans;
    }
};
