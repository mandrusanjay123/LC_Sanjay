#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.resize(rows + 1, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, col] = parseCell(cell);
        sheet[row][col] = value;
        cout << row << "." << col << "," << sheet[row][col] << endl;
    }

    void resetCell(string cell) {
        auto [row, col] = parseCell(cell);
        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        // Remove spaces and optional leading '='
        string f;
        f.reserve(formula.size());
        for (char c : formula) if (!isspace((unsigned char)c)) f.push_back(c);
        if (!f.empty() && f[0] == '=') f.erase(f.begin());

        // Evaluate expression with + and - (left-to-right, no precedence beyond that)
        // Terms can be: number, cell (A1), or range (A1:B3).
        int i = 0, n = (int)f.size();
        long long result = 0;
        int sign = 1;

        while (i < n) {
            if (f[i] == '+') { sign = 1; ++i; continue; }
            if (f[i] == '-') { sign = -1; ++i; continue; }

            // Parse one term
            long long termVal = 0;

            if (isdigit((unsigned char)f[i])) {
                // Number
                long long val = 0;
                while (i < n && isdigit((unsigned char)f[i])) {
                    val = val * 10 + (f[i] - '0');
                    ++i;
                }
                termVal = val;
            } else if (isalpha((unsigned char)f[i])) {
                // Cell reference or range
                string cell1 = parseCellToken(f, i); // advances i
                if (i < n && f[i] == ':') {
                    ++i; // skip ':'
                    string cell2 = parseCellToken(f, i);
                    termVal = sumRange(cell1, cell2);
                } else {
                    termVal = readCell(cell1);
                }
            } else {
                // Unexpected char; skip to avoid infinite loop
                ++i;
                continue;
            }

            result += sign * termVal;
        }

        // clamp to int range if you want; here we just cast
        return (int)result;
    }

private:
    static pair<int,int> parseCell(const string& cell) {
        // Expect like "A1" or "c23". Only single-letter columns A..Z per your 26-width design.
        int col = tolower(cell[0]) - 'a';
        int row = 0;
        for (size_t k = 1; k < cell.size(); ++k) {
            if (!isdigit((unsigned char)cell[k])) break;
            row = row * 10 + (cell[k] - '0');
        }
        // Basic guard
        col = max(0, min(25, col));
        if (row < 0) row = 0;
        return {row, col};
    }

    // Reads a cell token starting at f[pos] like "A1" and advances pos
    static string parseCellToken(const string& f, int& pos) {
        int start = pos;
        if (pos < (int)f.size() && isalpha((unsigned char)f[pos])) {
            ++pos; // single letter column
            while (pos < (int)f.size() && isdigit((unsigned char)f[pos])) ++pos;
        }
        return f.substr(start, pos - start);
    }

    int readCell(const string& cell) const {
        auto [row, col] = parseCell(cell);
        if (row >= 0 && row < (int)sheet.size() && col >= 0 && col < 26) {
            return sheet[row][col];
        }
        return 0; // out-of-bounds treated as 0
    }

    long long sumRange(const string& a, const string& b) const {
        auto [r1, c1] = parseCell(a);
        auto [r2, c2] = parseCell(b);
        if (r1 > r2) swap(r1, r2);
        if (c1 > c2) swap(c1, c2);
        r1 = max(0, r1);
        r2 = min((int)sheet.size() - 1, r2);
        c1 = max(0, c1);
        c2 = min(25, c2);
        long long s = 0;
        for (int r = r1; r <= r2; ++r) {
            for (int c = c1; c <= c2; ++c) s += sheet[r][c];
        }
        return s;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
