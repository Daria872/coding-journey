class Solution {
public:
    int dp[601][101][101];
    int solve(vector<pair<int,int>>&count, int m, int n, int indx){
        //base case
        //when indx goes out of bound or when m and n deplete
        if(indx>=count.size())
            return 0;
        if(dp[indx][m][n]!=-1)
            return dp[indx][m][n];
        int take=0;
        //take only if boundary conditions are satisfied
        //m and n exists
        if(count[indx].first<=m && count[indx].second<=n){
        take=1+solve(count,m-count[indx].first,n-count[indx].second,indx+1);
        }
        //skip
        int skip=solve(count,m,n,indx+1);
        return dp[indx][m][n]=max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>count;
        //push the values of frequency to count
        for(int i=0;i<strs.size();i++){
            int countZeros=0;
            int countOnes=0;
            for(const char &ch:strs[i]){
                if(ch=='0'){
                    countZeros+=1;
                }
                else{
                    countOnes+=1;
                }
            }
            count.push_back({countZeros,countOnes});
        }
        memset(dp,-1,sizeof(dp));
        int res=solve(count,m,n,0);
        return res;
    }
};