class Solution {
public:
    static bool isvowel(char c){
        c = tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    static string lower(string s){
        for(char &c: s) c = tolower(c);
        return s;
    }
    static string devowel(string s){
        for(char &c: s){
            char d = tolower(c);
            if(d=='a'||d=='e'||d=='i'||d=='o'||d=='u') c='*';
            else c=d;
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> firstByLower;
        unordered_map<string,string> firstByDevowel;

        for (const string& w : wordlist) {
            string lw = lower(w);
            string vw = devowel(w);
            if (!firstByLower.count(lw))   firstByLower[lw] = w;     // first occurrence
            if (!firstByDevowel.count(vw)) firstByDevowel[vw] = w;   // first occurrence
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const string& q : queries) {
            if (exact.count(q)) {                    // exact
                ans.push_back(q);
                continue;
            }
            string lq = lower(q);
            auto it1 = firstByLower.find(lq);        // case-insensitive
            if (it1 != firstByLower.end()) {
                ans.push_back(it1->second);
                continue;
            }
            string vq = devowel(q);                  // vowel error
            auto it2 = firstByDevowel.find(vq);
            if (it2 != firstByDevowel.end()) {
                ans.push_back(it2->second);
            } else {
                ans.push_back("");
            }
        }
        return ans;
    }
};
