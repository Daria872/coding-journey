class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int lp=0,rp=height.size()-1;
        while(lp<rp){
            int wt=rp-lp;
            int ht=min(height[lp],height[rp]);
            int area=wt*ht;
            maxarea=max(maxarea,area);
            height[lp]<height[rp]?lp++:rp--;
        }
        return maxarea;
    }
};