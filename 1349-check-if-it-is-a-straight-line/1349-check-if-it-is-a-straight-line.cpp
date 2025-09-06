class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy=coordinates[1][1]-coordinates[0][1];
        int dx=coordinates[1][0]-coordinates[0][0];
        
        for(int i=2;i<coordinates.size();i++){
            int dyi=coordinates[i][1]-coordinates[0][1];
            int dxi=coordinates[i][0]-coordinates[0][0];
            if(dy*dxi!=dx*dyi)
                return false;
        }
        return true;
    }
};