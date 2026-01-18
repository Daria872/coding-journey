class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        
        vector<pair<int,int>> machines;
        for (int i = 0; i < n; i++) {
            machines.push_back({costs[i], capacity[i]});
        }

        // Sort by cost
        sort(machines.begin(), machines.end());

        // Prefix maximum capacity
        vector<int> prefixMax(n);
        prefixMax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], machines[i].second);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cost_i = machines[i].first;
            int cap_i = machines[i].second;

            // Single machine case
            if (cost_i < budget) {
                ans = max(ans, cap_i);
            }

            // Two machine case
            int remaining = budget - cost_i;
            if (remaining <= 0) continue;

            // Binary search for largest index with cost < remaining
            int left = 0, right = i - 1;
            int idx = -1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (machines[mid].first < remaining) {
                    idx = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, cap_i + prefixMax[idx]);
            }
        }

        return ans;
    }
};
