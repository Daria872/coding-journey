class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mpp;
        for(char &ch:s){
            mpp[ch]++;
        }
        for(char &ch:t){
            mpp[ch]--;
            if(mpp[ch]<0){
                return ch;
            }
        }
        return 'x';
    }
};