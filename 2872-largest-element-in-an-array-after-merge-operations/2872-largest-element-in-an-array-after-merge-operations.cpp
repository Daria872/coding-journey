class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int i,n=nums.size();
        long long nextElement=nums[n-1];
        long long maxi=nums[n-1];
        for(i=n-2;i>=0;i--){
            if(nums[i]<=nextElement)
                nextElement+=nums[i];
            else
                nextElement=nums[i];
            maxi=max(maxi,nextElement);
        }
        return maxi;
    }
};