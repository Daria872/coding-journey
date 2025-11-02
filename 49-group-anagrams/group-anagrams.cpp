class Solution {
public:
    string generate(string &word){
        vector<int>hash(26,0);
        for(int i=0;i<word.size();i++){
            hash[word[i]-'a']++;
        }
        string new_word="";
        for(int i=0;i<26;i++){
            int freq=hash[i];
            if(freq>0){
                new_word+=string(hash[i],i+'a');
                }
            }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            string new_word=generate(temp);
            mpp[new_word].push_back(temp);
        }
        for(auto &it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};