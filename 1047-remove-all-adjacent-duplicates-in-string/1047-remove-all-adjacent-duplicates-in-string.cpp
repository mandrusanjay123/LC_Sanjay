class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int j=0;
        string ans;
        while(j<s.length()){
            if(!st.empty()&&st.top()==s[j]){
                st.pop();
            }
            else{
                st.push(s[j]);
            }
            j++;
        }
        ans.resize(st.size());
        int n=st.size()-1;
        while(!st.empty()){
            ans[n]=st.top();
            n--;
            st.pop();
        }
        // sort(ans.rbegin(),ans.rend());
        return ans;
    }
};