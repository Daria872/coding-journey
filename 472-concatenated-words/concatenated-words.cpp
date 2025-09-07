class Solution {
public:
    unordered_map<string,bool>mp;
    bool isConcatenated(string &w, unordered_set<string> &st){
        if(mp.find(w)!=mp.end())
            return mp[w];
        int l=w.size();
        for(int i=0;i<l;i++){
            string pre=w.substr(0,i+1);
            string suf=w.substr(i+1);

            if((st.find(pre)!=st.end() && st.find(suf)!=st.end()) || (st.find(pre)!=st.end() && isConcatenated(suf,st)))
                return mp[w]=true;
        }
        return mp[w]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>res;
        mp.clear();
        unordered_set<string>st(begin(words),end(words));
        int n=words.size();
        for(int i=0;i<n;i++){
            string w=words[i];
            if(isConcatenated(w,st))
                res.push_back(w);
        }
        return res;
    }
};