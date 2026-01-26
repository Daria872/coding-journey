class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>nonNeg;
        for(int x:nums){
            if(x>=0) nonNeg.push_back(x);
        }
        if(nonNeg.empty()){
            return nums;
        }
        k%=nonNeg.size();
        vector<int>rotated;
        for(int i=k;i<nonNeg.size();i++){
            rotated.push_back(nonNeg[i]);
        }
        for(int i=0;i<k;i++){
            rotated.push_back(nonNeg[i]);
        }
        vector<int>result=nums;
        int indx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                result[i]=rotated[indx++];
            }
        }
        return result;
    }
};