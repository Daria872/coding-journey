class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int low=0,high=m-1,ans=m;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(spells[i]*(long long)potions[mid]>=success){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            res[i]=m-ans;
        }
        return res;
    }
};