class Solution {
public:
    bool isAnagram(string &s1, string &s2){
        vector<int>arr(26,0);
        for(char &ch: s1){
            arr[ch-'a']++;
        }
        for(char &ch: s2){
            arr[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>result;
        result.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!isAnagram(words[i],result.back())){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};