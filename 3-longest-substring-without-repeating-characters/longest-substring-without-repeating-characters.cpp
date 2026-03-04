class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>lastIndex(256,-1);
        int start=0;
        int maxi=0;
        for(int end=0;end<s.size();end++){
            start=max(start,lastIndex[s[end]]+1);
            maxi=max(maxi,end-start+1);
            lastIndex[s[end]]=end;
        }
        return maxi;
    }
};