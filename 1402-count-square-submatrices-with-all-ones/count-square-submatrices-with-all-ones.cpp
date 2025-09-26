class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        //store the first row elements as it is
        for(int i=0;i<n;i++){
            res[i][0]=matrix[i][0];
        }
        //store the first column as it is
        for(int i=0;i<m;i++){
            res[0][i]=matrix[0][i];
        }
        //start iterating for the other elements
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0) res[i][j]=0;
                else{
                res[i][j]=min({res[i-1][j],res[i-1][j-1],res[i][j-1]})+1;
            }
        }
    }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=res[i][j];
            }
        }
        return sum;
    }
};