class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int even_xor=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                even_xor|=nums[i];
        }
        return even_xor;
    }
};