class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        int cum=0;
        for(int i=0;i<nums.size();i++){
            int lsum=cum;
            int rsum=s-lsum-nums[i];
            if(lsum==rsum)
                return i;
            //otherwise update the cumulative sum
            cum+=nums[i];
        }
        return -1;
    }
};