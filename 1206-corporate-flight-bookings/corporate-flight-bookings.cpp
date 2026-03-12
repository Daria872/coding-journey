class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);

        for(auto &it:bookings){
            int l=it[0];
            int r=it[1];
            int p=it[2];

            diff[l]+=p;
            if(r+1<=n){
                diff[r+1]-=p;
            }
        }
        
        for(int i=1;i<=n;i++){
            diff[i]=diff[i]+diff[i-1];
        }
        
        return vector<int>(diff.begin()+1,diff.begin()+n+1);
    }
};