class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result1=(a|b)^c;
        int result2=(a&b);
        int result3=result1&result2;
        return __builtin_popcount(result1)+__builtin_popcount(result3);
    }
};