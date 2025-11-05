class Solution {
public:
    int partitionString(string s) {
        vector<int>hash(26,0);
        int count=1;
        for(char &c:s){
            int indx=c-'a';
            if(hash[indx]){
                count++;
                fill(hash.begin(),hash.end(),0);
            }
            hash[indx]=1;
        }
        return count;
    }
};