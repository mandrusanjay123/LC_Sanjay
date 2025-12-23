class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                st.push(s[i]);
            }
            else if(st.size()>0){
            if(s[i]=='}'){
                if(st.top()=='{'){
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    st.pop();
                    continue;
                }
                else return false;
            }
            else if(s[i]==']'){
                if(st.top()=='['){
                    st.pop();
                    continue;
                }
                else return false;
            }
            }
            else return false;
        }
        return (st.size()==0)?true:false;
    }
};