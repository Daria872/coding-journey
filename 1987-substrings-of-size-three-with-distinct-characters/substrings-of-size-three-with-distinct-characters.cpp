class Solution {
public:
    int countGoodSubstrings(string s) {
        int l=0,r=2,count=0;
        while(r<s.size()){
            set<char>st;
            int p=0;
            for(int i=l;i<=r;i++){
                if(st.find(s[i])==st.end()){
                    st.insert(s[i]);
                }
            }
            if(st.size()==3)
                count++;
            l+=1;
            r+=1;
        }
        return count;
    }
};