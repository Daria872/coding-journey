class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int>ans={-1,-1};
        int max_qf=-1e9;
        for(auto &tower:towers){
            int dis=abs(tower[0]-center[0])+abs(tower[1]-center[1]);
            if(dis>radius) continue;
            else{
                if(tower[2]>max_qf){
                    max_qf=tower[2];
                    ans={tower[0],tower[1]};
                }
                else if(tower[2]==max_qf){
                    if(tower[0]<ans[0] || (tower[0]==ans[0] && tower[1]<ans[1])){
                        ans={tower[0],tower[1]};
                    }
                }
            }
        }
        return ans;
    }
};