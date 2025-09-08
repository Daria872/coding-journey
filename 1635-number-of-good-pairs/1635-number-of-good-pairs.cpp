class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int res=0;
        for(auto it:mpp){
            int freq=it.second;
            res+=((freq*(freq-1))/2);
        }
        return res;
    }
};