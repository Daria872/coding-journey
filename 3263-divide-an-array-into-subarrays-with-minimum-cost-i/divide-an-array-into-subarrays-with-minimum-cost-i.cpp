class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int smallest=INT_MAX,ssmallest=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<smallest){
                ssmallest=smallest;
                smallest=nums[i];
            }
            else if(nums[i]<ssmallest){
                ssmallest=nums[i];
            }
        }
        return nums[0]+ssmallest+smallest;
    }
};