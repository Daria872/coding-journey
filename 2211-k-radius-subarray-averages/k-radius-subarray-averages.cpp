class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n=nums.size();
        vector<int>result(n,-1);
        if(n<2*k+1){
            return result;
        }
        long long window=0;
        int left=0, right=2*k;
        for(int ind=left;ind<=right;ind++){
            window+=nums[ind];
        }
        int count=2*k+1;
        int avg=window/count;
        int i=k;
        result[i]=avg;
        right++;
        i++;
        while(right<n){
            int out_of_window=nums[left];
            int into_window=nums[right];
            window+=into_window-out_of_window;
            result[i]=window/count;
            right++;
            left++;
            i++;
        }
        return result;
    }
};