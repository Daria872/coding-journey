class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int l = 0, r = k-1;
        long long curr_sum = 0, ans = 0;
        unordered_map<int,int>frequency;
        for(int i=l;i<=r;i++){
            curr_sum+=nums[i];
            frequency[nums[i]]++;
        }
        if(frequency.size()==k){
            ans=curr_sum;
        }
        while(r+1<nums.size()){
            curr_sum-=nums[l];
            frequency[nums[l]]--;
            if(frequency[nums[l]]==0)
                frequency.erase(nums[l]);
            l++;
            r++;
            curr_sum+=nums[r];
            frequency[nums[r]]++;
            if(frequency.size()==k){
                ans=max(ans,curr_sum);
            }
        }
        return ans;
    }
};