class Solution {
public:
bool isFreq(int freq1[], int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        int i;
        for(i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int windowsize=s1.size();
        for(int i=0;i<s2.size();i++){
            int windowFreq[26]={0};
            int windowIndx=0, indx=i;
            while(windowIndx<windowsize && indx<s2.size()){
                windowFreq[s2[indx]-'a']++;
                windowIndx++;
                indx++;
            }
        if(isFreq(freq,windowFreq)) {
        return true;}
    }
    return false;
    }
};