class Solution {
public:
    int countEven(int num) {
        int count=0;
        for(int i=1;i<=num;i++){
            int temp=i;
            int s=0;
            while(temp!=0){
                int d=temp%10;
                s+=d;
                temp/=10;
            }
            if(s%2==0){
                count++;
            }
        }
        return count;
    }
};