class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int count=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                count++;
            }
            else{
                break;
            }
        }
        return n-count;
    }
};