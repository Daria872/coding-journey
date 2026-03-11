class Solution {
public:

    typedef pair<int,int>P;

    struct lambda{
        bool operator()(P &P1, P &P2){
            return P1.second<P2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<P,vector<P>,lambda>pq;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            pq.push({it.first,it.second});
        }

        vector<int>res;

        for(int i=1;i<=k;i++){
            P high_freq=pq.top();
            pq.pop();
            res.push_back(high_freq.first);
        }

        return res;
    }
};