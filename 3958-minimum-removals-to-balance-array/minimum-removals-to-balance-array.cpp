class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int removals=0;
        int i=0,maxlen=0;
        sort(nums.begin(),nums.end());
        //j points to the maximum element
        for(int j=0;j<nums.size();j++){
            while(nums[j]>(long long)k*nums[i]){
                i++;
            }
            maxlen=max(maxlen,j-i+1);
        }
        return nums.size()-maxlen;
    }
};