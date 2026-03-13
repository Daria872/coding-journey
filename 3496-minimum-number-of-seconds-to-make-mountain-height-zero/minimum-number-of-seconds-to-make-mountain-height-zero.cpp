class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left=1, right=1e18;
        long long ans=right;
        while(left<=right){
            long long mid=(left+right)/2;
            long long heightReduced=0;
            for(long long t: workerTimes){
                long long val=(2*mid)/t;
                long long x=(sqrt(1+4*val)-1)/2;
                heightReduced+=x;
                if(heightReduced>=mountainHeight){
                    break;
                }
            }
            if(heightReduced>=mountainHeight){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};