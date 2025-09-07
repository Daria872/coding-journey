class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            ans=min(ans,nums[mid]);
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low=low+1;
                high=high-1;
            }
            else if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
//use if, else-if, else for sequential flow
//without duplicates
//identify the sorted half and find the minimum element in the sorted half then eliminate it and find the element in the unsorted half
//optimisation: if the whole array or a subarray is sorted then just apply an overall condition for the range and break off early

//with duplicates
//edge cases:
//1. If there is a single element then ans will return a hige number so inside the loop set ans=min(ans, nums[mid])
//2. In case of duplicates , we can't check if the whole array is sorted as since duplicates are present we can't break too early
//3. Follow duplicate conditions
//4. Do not use if, if, else use if, else-if,else to maintain sequence