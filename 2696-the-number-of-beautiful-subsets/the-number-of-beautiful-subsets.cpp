class Solution {
public:
    int result=0;
    int K;
    void solve(int indx, vector<int>&nums, unordered_map<int,int>&mpp){
        if(indx==nums.size()){
            result++;
            return;
        }
        //not take
        solve(indx+1,nums,mpp);
        //take
        if(mpp.find(nums[indx]-K)==mpp.end() && mpp.find(nums[indx]+K)==mpp.end()){
            mpp[nums[indx]]++;
            solve(indx+1,nums,mpp);
            mpp[nums[indx]]--;
            if(mpp[nums[indx]]==0)
                mpp.erase(nums[indx]);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k)  {
        K=k;
        unordered_map<int,int>mpp;
        solve(0,nums,mpp);
        return result-1;
    }
};