class Solution {
public:
    int longestBalanced(string s) {
        int max_len = 0;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char,int> freq;

            for(int j = i; j < s.length(); j++){

                freq[s[j]]++;   // update first

                int first = freq.begin()->second;
                bool ok = true;

                for(auto &p : freq){
                    if(p.second != first){
                        ok = false;
                        break;
                    }
                }

                if(ok){
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};
