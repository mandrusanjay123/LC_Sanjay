class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       long long bestDiag2 = -1;  // squared diagonal
        int bestArea = 0;
        for (auto &v : dimensions) {
            long long w = v[0], h = v[1];
            long long d2 = w*w + h*h;   // no sqrt
            int area = (int)(w*h);
            if (d2 > bestDiag2) {
                bestDiag2 = d2;
                bestArea = area;
            } else if (d2 == bestDiag2 && area > bestArea) {
                bestArea = area;
            }
        }
        return bestArea;
    }
};