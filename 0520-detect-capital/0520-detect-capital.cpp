class Solution {
public:
    int countCapital(string word){
        int cnt=0;
        for(char ch:word){
            if(isupper(ch)){
                cnt++;
            }
        }
        return cnt;
    }
    bool detectCapitalUse(string word) {
        int cnt_cap=countCapital(word);
        if(cnt_cap==0) return true;
        if(cnt_cap==word.size()) return true;
        if(cnt_cap==1 && isupper(word[0])) return true;
        return false;
    }
};