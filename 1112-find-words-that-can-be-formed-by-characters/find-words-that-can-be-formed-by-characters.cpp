class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>charsCount(26,0);
        for(char &ch:chars){
            charsCount[ch-'a']++;
        }
        int result=0;
        for(string &word: words){
            vector<int>wordsCount(26,0);
            for(char &ch:word){
                wordsCount[ch-'a']++;
            }

            bool ok=true;
            for(int i=0;i<26;i++){
                if(charsCount[i]<wordsCount[i]){
                    ok=false;
                    break;
                }
            }
            if(ok==true)
                result+=word.size();
        }
        return result;
    }
};
