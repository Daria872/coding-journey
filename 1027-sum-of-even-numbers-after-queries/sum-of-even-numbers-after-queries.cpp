class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        //find the sum of all even numbers in the original array
        int sumEven=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                sumEven+=nums[i];
        }
        //now perform the operations
        vector<int>result;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int indx=queries[i][1];
            if(nums[indx]%2==0)
                sumEven-=nums[indx];
            nums[indx]=nums[indx]+val;
            if(nums[indx]%2==0)
                sumEven+=nums[indx];
            result.push_back(sumEven);
        }
        return result;
    }
};