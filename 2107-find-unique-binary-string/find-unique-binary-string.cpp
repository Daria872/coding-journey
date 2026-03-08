class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> s(nums.begin(), nums.end());

        for(int i = 0; i < (1 << n); i++) {
            string candidate = "";
            for(int j = n-1; j >= 0; j--) {
                candidate += ((i >> j) & 1) ? '1' : '0';
            }
            if(!s.count(candidate)) return candidate;
        }
        return ""; // should never reach here
    }
};