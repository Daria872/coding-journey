class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z') s[i]+=32;
            if(i>0 && s[i]!=s[i-1]) count++;
        }
        return count;
    }
};