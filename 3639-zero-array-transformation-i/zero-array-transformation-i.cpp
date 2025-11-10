class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        //create a diff array
        vector<int>diff(n,0);
        for(auto &query: queries){
            int start=query[0];
            int end=query[1];
            int x=1;
            diff[start]+=x;
            if(end+1<n){
                diff[end+1]-=x;
            }
        }
        //create a result array for comparison
        vector<int>result(n,0);
        //find the cumulative sum
        int cumsum=0;
        for(int i=0;i<n;i++){
            cumsum+=diff[i];
            result[i]=cumsum;
        }
        //comparison
        for(int i=0;i<n;i++){
            if(nums[i]>result[i])
                return false;
        }
        return true;
    }
};