class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //generate all substrings and check if the binary codes exist in the substrings
        int codes=(1<<k);
        unordered_set<string>st;
        for(int i=k;i<=s.size();i++){
            string sub=s.substr(i-k,k);
            if(!st.count(sub)){
                st.insert(sub);
                codes--;
            }
            if(codes==0)
                return true;
        }
        return false;
    }
};