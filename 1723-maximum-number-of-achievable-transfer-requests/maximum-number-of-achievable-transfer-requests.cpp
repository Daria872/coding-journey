class Solution {
public:
    int result=INT_MIN;
    int m;
    void solve(int indx, int count, int n, vector<int>&resultant, vector<vector<int>>&requests){
        //base case
        if(indx>=m){
            //check if all are zeros
            bool allzeros=true;
            for(int &x: resultant){
                if(x!=0){
                    allzeros=false;
                    break;
                }
            }
            if(allzeros==true)
                result=max(result,count);
            return;
        }
        int from=requests[indx][0];
        int to=requests[indx][1];
        resultant[from]--;
        resultant[to]++;
        //explore
        solve(indx+1,count+1,n,resultant,requests);
        //backtrack
        resultant[from]++;
        resultant[to]--;
        //explore again
        solve(indx+1,count,n,resultant,requests);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m=requests.size();
        vector<int>resultant(n,0);
        solve(0,0,n,resultant,requests);
        return result;
    }
};