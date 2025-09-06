class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,startingInd=-1,minlen=INT_MAX,cnt=0;
        vector<int>hash(256,0);
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<s.size()){
            hash[s[r]]--;
            if(hash[s[r]]>=0){
                cnt++;
            }
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    startingInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt-=1;
                }
                l++;
            }
            r++;
        }
        return startingInd==-1?"":s.substr(startingInd,minlen);
    }
};