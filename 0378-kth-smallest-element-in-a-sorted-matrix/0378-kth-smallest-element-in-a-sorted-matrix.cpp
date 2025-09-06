class Solution {
public:
    int countSmallerMid(vector<vector<int>>& matrix, int mid){
        int n=matrix.size();
        int row=0,col=n-1,count=0;
        while(row<n && col>=0){
            if(matrix[row][col]<=mid){
                //all the elements of that row upto the current column will be smaller than mid
                count+=(col+1);
                row++;
            }
            else{
                col--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans=0;
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high){
            int mid=(low+high)/2;
            int count=countSmallerMid(matrix,mid);
            if(count<k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};