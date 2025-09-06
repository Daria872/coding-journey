class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1=word1.size(),n2=word2.size();
        int i=0,j=0;
        int wi=0,wj=0;
        while(wi<n1 && wj<n2){
            if(word1[wi][i]!=word2[wj][j])
                return false;
            i++;
            j++;
            if(i==word1[wi].size()){
                i=0;
                wi++;
            }
            if(j==word2[wj].size()){
                j=0;
                wj++;
            }
        }
        if(wi==n1 && wj==n2)
            return true;
        return false;
}
};