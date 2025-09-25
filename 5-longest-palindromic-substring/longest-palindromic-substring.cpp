class Solution {
public:
    bool isPalindrome(string &s, int low, int high){
        while(low<=high){
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        //generating all substrings
        int n=s.size();
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j) && j-i+1>maxlen){
                    start=i;
                    maxlen=j-i+1;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};