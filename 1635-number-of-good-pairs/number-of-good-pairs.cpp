class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            res+=mpp[nums[i]];
            mpp[nums[i]]++;
        }
        return res;
    }
};