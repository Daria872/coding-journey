class Solution {
public:
    string makeGood(string s) {
        int i=0;
        string res;
        while(i<s.size()){
            if(!res.empty() && abs(res.back()-s[i])==32){
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};