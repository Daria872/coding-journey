class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>cols(9);
        vector<unordered_set<char>>box(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                char num=board[i][j];
                int boxNum=(i/3)*3+(j/3);
                if(rows[i].count(num) || cols[j].count(num) || box[boxNum].count(num)) return false;
                rows[i].insert(num);
                cols[j].insert(num);
                box[boxNum].insert(num);
            }
        }
        return true;
    }
};