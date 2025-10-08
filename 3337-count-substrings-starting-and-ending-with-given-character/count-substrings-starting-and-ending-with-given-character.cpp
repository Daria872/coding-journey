class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                ans+=(1+count);
                count++;
            }
        }
        return ans;
    }
};