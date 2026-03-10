class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0, r=k-1, sum=0;
        double avg=0;
        for(int i=l;i<=r;i++){
            sum+=nums[i];
        }
        avg=(double)sum/k;
        while(r+1<nums.size()){
            sum-=nums[l];
            l++;
            r++;
            sum+=nums[r];
            double curr_avg=(double)sum/k;
            avg=max(avg,curr_avg);
        }
        return avg;
    }
};