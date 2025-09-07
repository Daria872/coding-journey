class Solution {
public:
    string baseNeg2(int n) {
        string rem="";
        if(n==0) return "0";
        while(n!=0){
            if((abs(n))%2==1){
                rem+="1";
                n=(n-1)/-2;
            }
            else{
                rem+="0";
                n=n/-2;
            }
        }
        reverse(rem.begin(),rem.end());
        return rem;
    }
};


