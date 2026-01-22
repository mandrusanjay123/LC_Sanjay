class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        recursion(0,s.length(),temp,ans,s);
        return ans;
    }

void recursion(int id,int n,vector<string>&temp, vector<vector<string>>&ans,string s){
    if(id==n){
        ans.push_back(temp);
        return;
    }
    for(int i=id;i<n;i++){
        //0 to id -->substr1
        //id=1 to n-1--?substr2

        if(ispalindrome(s,id,i)){
            temp.push_back(s.substr(id,i-id+1));
            recursion(i+1,n,temp,ans,s);
            temp.pop_back();
        }
    }
    return;
}

    bool ispalindrome(string s,int l,int r){
    // int l=0;
    // int r=s.length()-1;
    while(l<r){
        if(s[l++]!=s[r--])return false;
    }
    return true;
}
};