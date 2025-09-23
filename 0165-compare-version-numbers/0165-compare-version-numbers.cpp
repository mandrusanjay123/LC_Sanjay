class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        const int n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            // Extract next segment from version1
            string a;
            while (i < n && version1[i] != '.') a.push_back(version1[i++]);
            // skip the dot
            if (i < n && version1[i] == '.') ++i;

            // Extract next segment from version2
            string b;
            while (j < m && version2[j] != '.') b.push_back(version2[j++]);
            if (j < m && version2[j] == '.') ++j;

            // Trim leading zeros
            int p = 0; while (p < (int)a.size() && a[p] == '0') ++p;
            int q = 0; while (q < (int)b.size() && b[q] == '0') ++q;
            a = (p == (int)a.size()) ? "0" : a.substr(p);
            b = (q == (int)b.size()) ? "0" : b.substr(q);

            // Compare by length first to avoid overflow
            if (a.size() < b.size()) return -1;
            if (a.size() > b.size()) return 1;

            // Same length: lexicographic compare
            if (a < b) return -1;
            if (a > b) return 1;
            // else equal for this segment, continue
        }
        return 0;
    }
};
