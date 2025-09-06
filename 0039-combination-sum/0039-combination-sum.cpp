class Solution {
public:
    void findCombination(int ind, vector<int>& candidates, int target, vector<int>ds, vector<vector<int>>&ans){
        int n=candidates.size();
        if(ind==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombination(ind,candidates,target-candidates[ind],ds,ans);
            ds.pop_back();
        }
        findCombination(ind+1,candidates,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,candidates, target, ds, ans);
        return ans;
    }
};