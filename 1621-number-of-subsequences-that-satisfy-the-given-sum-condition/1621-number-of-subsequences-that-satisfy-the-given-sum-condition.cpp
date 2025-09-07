class Solution {
public:
int M=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int res=0;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        vector<int>power(nums.size());
        power[0]=1;
        for(int i=1;i<nums.size();i++){
            power[i]=(power[i-1]*2)%M;
        }
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                res=(res%M+power[r-l])%M;
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};