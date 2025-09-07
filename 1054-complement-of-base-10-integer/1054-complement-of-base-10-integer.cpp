class Solution {
public:
    int bitwiseComplement(int n) {
        string rem="";
        if(n==0) return 1;
        while(n>0){
            if(n%2==1){
                rem+="1";
            }
            else{
                rem+="0";
            }
            n/=2;
        }
        reverse(rem.begin(),rem.end());
        string flip="";
        for(int i=0;i<rem.size();i++){
            if(rem[i]=='0')
            flip+='1';
            else
            flip+='0';
        }
        int num=0,p2=1,x=flip.size();
        for(int i=x-1;i>=0;i--){
            if(flip[i]=='1'){
                num+=p2;
            }
            p2*=2;
        }
        return num;
    }
};