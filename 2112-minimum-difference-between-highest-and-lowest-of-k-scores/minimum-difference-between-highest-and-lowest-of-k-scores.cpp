class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int l=0,r=k-1,mini=INT_MAX;
        sort(nums.begin(),nums.end());
        while(r<nums.size()){
            mini=min(mini,nums[r]-nums[l]);
            l++;
            r++;
        }
        return mini;
    }
};