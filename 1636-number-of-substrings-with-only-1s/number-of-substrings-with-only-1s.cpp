class Solution {
public:
    int numSub(string s) {
        int res=0;
        const int MOD=1e9+7;
        int consecutive=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                consecutive+=1;
            }
            else{
                consecutive=0;
            }
            res=(res+consecutive)%MOD;
        }
        return res;
    }
};