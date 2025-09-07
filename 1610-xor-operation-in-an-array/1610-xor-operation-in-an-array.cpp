class Solution {
public:
    int oper(int n){
        if(n % 4 == 1) return 1;
        else if(n % 4 == 2) return n + 1;
        else if(n % 4 == 3) return 0;
        else return n;
    }

    int xorOperation(int n, int start) {
        int s = start >> 1;
        int res = (s == 0 ? 0 : oper(s - 1)) ^ oper(s + n - 1);
        return (res << 1) | (n & start & 1);
    }
};
