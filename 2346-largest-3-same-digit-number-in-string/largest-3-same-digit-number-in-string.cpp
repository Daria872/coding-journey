class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar=0;
        for(int i=2;i<num.size();i++){
            if((num[i]==num[i-1] && num[i]==num[i-2]))
                maxChar=max(maxChar,num[i]);
        }
        if(maxChar==0) return "";
        return string(3,maxChar);
    }
};