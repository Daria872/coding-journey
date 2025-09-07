class Solution {
public:
    int func(vector<int>&nums, int k){
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=ceil((double)nums[i]/(double)k);
        }
        return totalsum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            int givensum=func(nums,mid);
            if(givensum<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};