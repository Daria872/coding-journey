class Solution {
public:
    int res=INT_MAX;
    void solve(int ind, vector<int>&cookies, vector<int>&children, int k){
        int n=cookies.size();
        if(ind>=n){
            int maxi=*max_element(children.begin(),children.end());
            res=min(res,maxi);
            return;
        }
        int cookie=cookies[ind];
        for(int i=0;i<children.size();i++){
            children[i]+=cookie;
            solve(ind+1,cookies,children,k);
            children[i]-=cookie;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>children(k);
        solve(0,cookies, children, k);
        return res;
    }
};