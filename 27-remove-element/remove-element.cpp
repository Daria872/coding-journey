class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0) return 0;
        int i=-1;
        for(int k=0;k<n;k++){
            if(nums[k]==val){
                i=k;
                break;
            }
        }
        if(i==-1) return n;
        int j=i+1;
        while(j<n){
            if(val!=nums[j]){
                swap(nums[i],nums[j]);
                i++;    
            }
        j++;
    }
    return i;
    }
};