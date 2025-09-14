class Solution {
public:
    unordered_set<string>ExactSet;
    unordered_map<string,string>CaseMap;
    unordered_map<string,string>VowelMap;
    
    string replaceVowel(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                s[i]='*';
        }
        return s;
    }
    string checkformatch(string & query){
        if(ExactSet.find(query)!=ExactSet.end()){
            return query;
        }
        string lowercase=query;
        for(char & ch: lowercase){
            ch=tolower(ch);
        }
        if(CaseMap.find(lowercase)!=CaseMap.end()){
            return CaseMap[lowercase];
        }
        string vowelcase=replaceVowel(lowercase);
        if(VowelMap.find(vowelcase)!=VowelMap.end()){
            return VowelMap[vowelcase];
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        ExactSet.clear();
        CaseMap.clear();
        VowelMap.clear();
        //First iterate through wordlist
        for(int i=0;i<wordlist.size();i++){
            //insert all the words into ExactSet
            ExactSet.insert(wordlist[i]);

            string lowerCase=wordlist[i];
            for(char & ch:lowerCase){
                ch=tolower(ch);
            }
            if(CaseMap.find(lowerCase)==CaseMap.end()){//if the word is not found regardless of its case
                CaseMap[lowerCase]=wordlist[i];
            }

            string vowelCase=replaceVowel(lowerCase);
            if(VowelMap.find(vowelCase)==VowelMap.end()){
                VowelMap[vowelCase]=wordlist[i];
            }
        }
        vector<string>result;
        for(int i=0;i<queries.size();i++){
            result.push_back(checkformatch(queries[i]));
        }
        return result;
    }
};