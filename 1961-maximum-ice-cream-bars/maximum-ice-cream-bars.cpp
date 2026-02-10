class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int bars=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                coins-=costs[i];
                bars++;
            }
            else{
                break;
            }
        }
        return bars;
    }
};