class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        vector<int>even;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                even.push_back(nums[i]);
        }
        for(int i=0;i<even.size();i++){
            res=res|even[i];
        }
        return res;
    }
};