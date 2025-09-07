class Solution {
public:
    bool possibleOrNot(vector<int>& bloomDay, int days, int m,int k){
        int cnt=0,noOfB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                cnt++;
            }
            else{
                noOfB+=(cnt/k);
                cnt=0;
            }
        }
        noOfB+=(cnt/k);

        if(noOfB>=m)
        return true;
        else
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=INT_MAX;
        if(1LL*m*k>bloomDay.size()) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possibleOrNot(bloomDay,mid,m,k)==true)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};