class Solution {
public:
    int atmostgoal(vector<int>&nums, int goal)
    {
        int l=0,r=0,s=0,cnt=0,n=nums.size();
        if(goal<0) return 0;
        while(r<n){
            s+=nums[r];
            while(s>goal){
                s-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostgoal(nums,goal)-atmostgoal(nums,goal-1);
    }
};