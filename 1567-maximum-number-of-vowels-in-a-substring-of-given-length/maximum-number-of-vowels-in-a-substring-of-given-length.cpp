class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxVowels(string s, int k) {
        int maxlen=0;
        int n=s.size();
        int l=0,r=0;
        int count=0;
        while(r<n){
            if(isVowel(s[r]))
                count++;
            if(r-l+1==k){
                maxlen=max(maxlen,count);
                if(isVowel(s[l]))
                    count--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};