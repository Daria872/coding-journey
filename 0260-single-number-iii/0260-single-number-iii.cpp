class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor1=0;
        for(int i=0;i<nums.size();i++){
            xor1=xor1^nums[i];
        }
        int rightmost=(xor1&(xor1-1))^xor1;
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++){
            if(rightmost&nums[i])
            b1^=nums[i];
            else
            b2^=nums[i];
        }
        return {b1,b2};
    }
};