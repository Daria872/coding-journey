class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>events;
        for(auto &log: logs){
            events.push_back({log[0],+1});
            events.push_back({log[1],-1});
        }
        sort(begin(events),end(events));
        int currPop=0,minYr=0,maxPop=0;
        for(auto &e:events){
            currPop+=e.second;
            if(currPop>maxPop){
                maxPop=currPop;
                minYr=e.first;
            }
        }
        return minYr;
    }
};