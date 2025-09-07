class Solution {
public:
    int maxPower(string s) {
        int maxi=1,x=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])
            x++;
            else{
                maxi=max(maxi,x);
                x=1;
            }
        }
        maxi=max(maxi,x);
        return maxi;
    }
};