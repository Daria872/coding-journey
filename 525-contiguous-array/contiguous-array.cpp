class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int zeros=0,ones=0,maxlen=0;

        mpp[0]=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zeros++;
            else
                ones++;

            int diff=ones-zeros;

            if(mpp.find(diff)!=mpp.end()){
                maxlen=max(maxlen,i-mpp[diff]);
            }
            else{
                mpp[diff]=i;
            }
        }
        
        return maxlen;
    }
};