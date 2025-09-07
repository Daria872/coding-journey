class Solution {
public:
    long long func(vector<int>& piles, int hourly) {
        long long totalhrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhrs += (piles[i] + hourly - 1) / hourly; // integer ceil
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long reqtime = func(piles, mid);
            if (reqtime <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
