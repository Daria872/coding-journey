class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long res=-1,tot=0;
        for(int i=0;i<nums.size();i++){
            if(tot>nums[i]){
                res=tot+nums[i];
            }
            tot+=nums[i];
        }
        return res;
    }
};