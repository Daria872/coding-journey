class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool allzero=true;
        int totXor=0;
        for(int i=0;i<n;i++){
            totXor^=nums[i];
            if(nums[i]!=0) allzero=false;
        }
        if(allzero) return 0;
        return totXor!=0?n:n-1;
    }
};