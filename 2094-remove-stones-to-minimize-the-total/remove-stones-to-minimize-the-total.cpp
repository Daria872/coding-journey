class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;

        //push all the elements of piles array into pq

        int sum=0;

        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
            sum+=piles[i];
        }

        for(int i=1;i<=k;i++){
            int maxi=pq.top();
            pq.pop();
            sum-=maxi;
            int res=maxi/2;
            int to_be_pushed=maxi-res;
            sum+=to_be_pushed;
            pq.push(to_be_pushed);
        }

        return sum;

    }
};