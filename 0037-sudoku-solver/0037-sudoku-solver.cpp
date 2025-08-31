class Solution {
public:
bool isvalid(vector<vector<char>>&board,int r,int c,int ch){
    for(int i=0;i<9;i++){
        if(board[r][i]==ch)return false;
        if(board[i][c]==ch)return false;
        if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false;
    }
    return true;
}
bool solve(vector<vector<char>>&board){
    for(int r=0;r<board.size();r++){
        for(int c=0;c<board[r].size();c++){
            if(board[r][c]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(isvalid(board,r,c,ch)){
                        board[r][c]=ch;
                        if(solve(board)==true)
                        return true;
                        else
                        board[r][c]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;

}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};