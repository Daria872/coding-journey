class Solution {
public:
    const vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>& board, int i, int j, int ind, string &word){
        int n=board.size();
        int m=board[0].size();
        if(ind==word.size())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$')
            return false;
        if(board[i][j]!=word[ind])
            return false;
        
        char temp=board[i][j];
        board[i][j]='$';

        for(auto [it1,it2]: directions){
            int new_i=i+it1;
            int new_j=j+it2;
            if(find(board,new_i,new_j,ind+1,word))
                return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(board,i,j,0,word))
                    return true;
            }
        }
        return false;
    }
};