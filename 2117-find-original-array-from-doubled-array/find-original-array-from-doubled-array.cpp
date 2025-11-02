class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2!=0)
            return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mpp;
        for(int &x:changed){
            mpp[x]++;
        }
        vector<int>result;
        for(int &num:changed){
            int twice=num*2;
            if(mpp[num]==0)
                continue;
            if(mpp.find(num)==mpp.end() || mpp[twice]==0)
                return {};
            result.push_back(num);
            mpp[num]--;
            mpp[twice]--;
        }
        return result;
    }
};