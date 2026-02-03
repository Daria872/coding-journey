class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>even,odd;
        for(int i=0;i<nums.size();i++){
            if(i%2!=0){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        int evenInd=0,oddInd=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=even[evenInd];
                evenInd++;
            }
            else{
                nums[i]=odd[oddInd];
                oddInd++;
            }
        }
        return nums;
    }
};