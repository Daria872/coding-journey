class Solution {
public:
    int minOperations(vector<int>& nums) {
        int countones=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                countones++;
            }
        }
        if(countones>=1){
            return n-countones;
        }
        int oprs=INT_MAX;
        for(int i=0;i<n-1;i++){
            int GCD=nums[i];
            for(int j=i+1;j<n;j++){
                GCD=gcd(GCD,nums[j]);
                if(GCD==1){
                    oprs=min(oprs,j-i);
                    break;
                }
            }
        }
        if(oprs==INT_MAX) return -1;
        return oprs+(n-1);
    }
};