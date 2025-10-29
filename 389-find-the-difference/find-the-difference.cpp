class Solution {
public:
    char findTheDifference(string s, string t) {
        int xor1=0;
        for(char &ch:s){
            xor1^=ch;
        }
        for(char &ch:t){
            xor1^=ch;
        }
        return (char)xor1;
    }
};