class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (k == 0) 
            return ans;
        if (k > n) 
            return ans;

        vector<int> comb(k);

        for (int i = 0; i < k; i++) 
            comb[i] = i + 1;

        while (true) {
            ans.push_back(comb);
            int i = k - 1;

            while (i >= 0 && comb[i] == n - (k - 1 - i)) {
                i--;
            }
            if (i < 0) 
                break;

            comb[i]++;

            for (int j = i + 1; j < k; j++) {
                comb[j] = comb[j - 1] + 1;
            }
        }
        return ans;
    }
};