class Solution {
public:
    int squareOfDigits(int n){
        int s=0,d;
        while(n>0){
            d=n%10;
            s+=(d*d);
            n=n/10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=squareOfDigits(n);
        while(fast!=1 && slow!=fast){
            slow=squareOfDigits(slow);
            fast=squareOfDigits(squareOfDigits(fast));
        }
        return fast==1;
    }
};