class Solution {
public:
    string simplifyPath(string path) {
        stack<char>s;
        string ans="";
        int i=0;
        bool noContinue=false;
        while(i<path.length()){
            string temp="";
            if(path[i]=='/'){
                if(!s.empty()&&s.top()=='/'){
                    i++;
                    continue;
                }
                else{
                    s.push('/');
                }
            }
            while(i<path.length()&&isalpha(path[i])||isdigit(path[i])){
                s.push(path[i++]);
                while(i<path.length()&&path[i]=='.'&&path[i]!='/'){
                    s.push(path[i++]);
                }

            }
            while(i<path.length()&&(path[i]=='.'||path[i]!='/')){
                temp+=path[i++];
                if(isalpha(path[i])){
                     for(char t:temp){
                    s.push(t);
                    temp="";
                }
                }
                while(i<path.length()&&isalpha(path[i])||isdigit(path[i])){
                    s.push(path[i++]);
                    noContinue=true;
                }
            }
            if(temp.length()>0){
            if(temp.length()==2&&!noContinue){
                if(s.top()=='/'){
                    s.pop();
                while(!s.empty()&&s.top()!='/'){
                    s.pop();
                }
            }
            }
            else if(temp.length()>2){
                for(char t:temp){
                    s.push(t);
                }
            }
            }
            noContinue=false;
        }
        if(!s.empty()&&s.top()=='/')s.pop();
        ans.resize(s.size());
        int id=s.size()-1;
        while(!s.empty()){
            ans[id--]=s.top();
            s.pop();
        }
        return (ans.length()==0)?"/":ans;
    }
};