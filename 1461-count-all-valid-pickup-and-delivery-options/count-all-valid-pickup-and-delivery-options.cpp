class Solution {
public:
    int M=1e9+7;

    int countOrders(int n) {
        long long result=1;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
            int spaces=(i-1)*2+1;
            int currperm=((spaces)*(spaces+1))/2;
            result*=currperm;
            result%=M;
        }
        return result;
    }
};