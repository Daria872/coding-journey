class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>hash(26,0);
        int max_v=0,max_c=0;
        for(int i=0;i<s.size();i++){
            hash[s[i]-'a']++;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                max_v=max(max_v,hash[s[i]-'a']);
            }
            else{
                max_c=max(max_c,hash[s[i]-'a']);
            }
        }
        return max_v+max_c;
    }
};