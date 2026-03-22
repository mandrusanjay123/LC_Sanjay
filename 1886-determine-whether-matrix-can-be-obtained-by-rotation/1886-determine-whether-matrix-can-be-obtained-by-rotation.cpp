class Solution {
public:
    int n;

    vector<vector<int>> rotate90(vector<vector<int>>& mat) {
        vector<vector<int>> rotate(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rotate[j][n - i - 1] = mat[i][j];
            }
        }
        return rotate;
    }

    bool isSame(vector<vector<int>>& a, vector<vector<int>>& b) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] != b[i][j]) return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        if(isSame(mat, target)) return true;

        for(int k = 0; k < 3; k++) {
            mat = rotate90(mat);
            if(isSame(mat, target)) return true;
        }

        return false;
    }
};