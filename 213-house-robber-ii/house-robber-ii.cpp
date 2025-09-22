class Solution {
public:
    int Max_Sum(vector<int>&nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=0+prev;
            int curi=max(take,nottake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //if the element has no other neighbours then, return the same element itself
        if(n==1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            //excluding the first element
            if(i!=0) temp1.push_back(nums[i]);
            //excluding the last element
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(Max_Sum(temp1),Max_Sum(temp2));
    }
};