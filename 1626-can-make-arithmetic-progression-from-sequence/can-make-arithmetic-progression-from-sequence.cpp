class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int mini=*min_element(arr.begin(),arr.end());
        int maxi=*max_element(arr.begin(),arr.end());
        int n=arr.size();
        if((maxi-mini)%(n-1)!=0) return false;
        int d=(maxi-mini)/(n-1);
        int i=0;
        while(i<n){
            //check if the element is in the correct position
            if(arr[i]==mini+(i*d))
                i++;
            //if it is not in the correct position, find it
            else{
                if((arr[i]-mini)%d!=0)
                return false;
                int j=(arr[i]-mini)/d;
                if(arr[i]==arr[j])
                return false;

            //once you find the correct position, swap
                swap(arr[i],arr[j]);
        }
        }
        return true;
    }
};