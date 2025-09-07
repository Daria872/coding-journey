class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal,cnt=0l;
        while(ans){
            ans=ans&(ans-1);
            cnt++;
        }
        return cnt;
    }
};