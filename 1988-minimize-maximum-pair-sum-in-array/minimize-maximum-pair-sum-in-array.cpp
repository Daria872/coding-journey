class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum=(nums[i]+nums[j]);
            res=max(res,sum);
            i++;
            j--;
        }
        return res;
    }
};