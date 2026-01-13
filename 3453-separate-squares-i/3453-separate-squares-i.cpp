class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;
        
        // Determine search range
        for (auto &s : squares) {
            low = min(low, (double)s[1]);
            high = max(high, (double)(s[1] + s[2]));
        }
        
        for (int i = 0; i < 100; i++) { // enough for 1e-5 precision
            double mid = (low + high) / 2.0;
            double diff = areaAbove(squares, mid) - areaBelow(squares, mid);
            
            if (diff > 0) {
                low = mid;   // too much area above
            } else {
                high = mid;  // too much area below
            }
        }
        return (low + high) / 2.0;
    }
    
    double areaAbove(const vector<vector<int>>& squares, double y) {
        double area = 0;
        for (auto &s : squares) {
            double bottom = s[1];
            double top = s[1] + s[2];
            double side = s[2];
            
            if (y <= bottom) {
                area += side * side;
            } else if (y < top) {
                area += side * (top - y);
            }
        }
        return area;
    }
    
    double areaBelow(const vector<vector<int>>& squares, double y) {
        double area = 0;
        for (auto &s : squares) {
            double bottom = s[1];
            double top = s[1] + s[2];
            double side = s[2];
            
            if (y >= top) {
                area += side * side;
            } else if (y > bottom) {
                area += side * (y - bottom);
            }
        }
        return area;
    }
};
