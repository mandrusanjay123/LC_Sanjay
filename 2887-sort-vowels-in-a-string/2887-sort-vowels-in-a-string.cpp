class Solution {
public:
bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return true;
    return false;
}
    string sortVowels(string s) {
        string vowels="";
        vector<int>indices;
        for(int i=0;i<s.length();i++){
            if(isvowel(s[i])){
            vowels+=s[i];
            indices.push_back(i);
            }
        }
        sort(vowels.begin(),vowels.end());
        for(int i=0;i<indices.size();i++){
            s[indices[i]]=vowels[i];
        }
    return s;
    }
};