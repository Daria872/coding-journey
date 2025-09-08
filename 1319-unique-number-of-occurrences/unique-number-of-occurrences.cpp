class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>hash(2001,0);
        for(int i=0;i<arr.size();i++){
            hash[1000+arr[i]]++;
        }
        sort(hash.begin(),hash.end());
        for(int i=1;i<2001;i++){
            if(hash[i]!=0 && hash[i-1]==hash[i]){
                return false;
            }
        }
        return true;
    }
};