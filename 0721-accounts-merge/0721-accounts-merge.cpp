class DSU{
unordered_map<string,string>parent;
public:
    string find(string root){
        if(parent.find(root)==parent.end()){
            parent[root]=root;
        }
        if(parent[root] == root)  
        return root;
        return parent[root]=find(parent[root]);
    }
    void unite(string a ,string b){
        string ra= find(a);
        string rb=find(b);
        if(ra!=rb){
            parent[rb]=ra;
        }
    }
};
class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //,my root will be email
       // as common email means same person so Ill take the parent map withkey emial so I can m ake one email as parent and makle them in one union set
       //next ill have two data structures one for maintaining the key as email and val as name so that Ill kno if i get a root ill have the name thi is dor printing at the end

       //now ill make 2nd map for grouping i.e one root mail id and set of a;l gthe united email ids so that ill return the answer ith atachng the key email respecive name and to all the sorted emails of that root 

    
       unordered_map<string,string>emailToName;
       unordered_map<string,set<string>>groups;
       DSU dsu;
       for(auto record:accounts){
        string name=record[0];
        for(int i=1;i<record.size();i++){
            emailToName[record[i]]=name;
            dsu.unite(record[1],record[i]);
        }
       }

       //now ill group the root email id to all its unique records as in a set

       for(auto &[email,_]:emailToName){
            string root=dsu.find(email);
            groups[root].insert(email);
       }
       vector<vector<string>>ans;
       for(auto &[root,email]:groups){
        string name=emailToName[root];
        vector<string>temp;
        temp.push_back(name);
        temp.insert(temp.end(),email.begin(),email.end());
        ans.push_back(temp);
       }
       return ans;

    }
};