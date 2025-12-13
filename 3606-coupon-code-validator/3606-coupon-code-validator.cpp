class Solution {
public:
     int rankOf(const string& bl) const {
        if (bl == "electronics") return 0;
        if (bl == "grocery")     return 1;
        if (bl == "pharmacy")    return 2;
        if (bl == "restaurant")  return 3;
        return 4;                // invalid
    }
    bool validCode(const string& code) const {
        if (code.empty()) return false;
        for (char c : code)
        if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_')
                return false;
        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine,vector<bool>&   isActive) {

        vector<pair<int,string>> pool;    

        
        for (size_t i = 0; i < code.size(); ++i) {
            if (!isActive[i]) continue;
            int r = rankOf(businessLine[i]);
            if (r == 4) continue;        
            if (!validCode(code[i])) continue;
            pool.emplace_back(r, code[i]); 
        }
        sort(pool.begin(), pool.end(),[](const auto& a, const auto& b) {
                 return (a.first != b.first) ? a.first < b.first: a.second < b.second;
             });

        vector<string> ans;
        ans.reserve(pool.size());
        for (auto& p : pool) ans.push_back(std::move(p.second));
        return ans;
    }
};