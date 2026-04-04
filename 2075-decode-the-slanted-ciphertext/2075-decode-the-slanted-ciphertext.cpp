class Solution {
public:
    static string decodeCiphertext(string& encodedText, int rows) {
        if (rows==1) return encodedText;
        int N=encodedText.size();
        int cols=N/rows;

        string dec;
        for (int start=0; start<cols; start++) {
            for (int r=0, c=start; r<rows && c<cols; r++, c++) {
                dec.push_back(encodedText[r*cols+c]);  
            }
        }

        while (!dec.empty() && dec.back()==' ')
            dec.pop_back();

        return dec;
    }
};