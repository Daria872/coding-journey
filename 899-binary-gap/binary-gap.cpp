class Solution {
public:
    int binaryGap(int n) {
        //convert the number to binary
       int last_one=-1,i=0,maxdist=0;
       while(n>0){
        if(n&1){//last bit is one{
            if(last_one!=-1){
                maxdist=max(maxdist,i-last_one);
            }
            last_one=i;
        }
        n>>=1;
        i++;
       }
       return maxdist;
    }
};