class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<long long, vector<long long>, greater<long long>>pq1;
        priority_queue<long long, vector<long long>, greater<long long>>pq2;

        long long sum=0;

        int n=costs.size();
        
        int i=0,j=costs.size()-1;

        //fill left candidates
        for(int c=0;c<candidates && i<=j; c++){
            pq1.push(costs[i++]);
        }

        //fill right candidates
        for(int c=0;c<candidates && i<=j; c++){
            pq2.push(costs[j--]);
        }

        while(k--){
            long long mini1=(pq1.empty())?LLONG_MAX:pq1.top();
            long long mini2=(pq2.empty())?LLONG_MAX:pq2.top();

            if(mini1<=mini2){
                sum+=mini1;
                pq1.pop();

                if(i<=j){
                    pq1.push(costs[i++]);
                }
            }
            else{
                sum+=mini2;
                pq2.pop();

                if(i<=j){
                    pq2.push(costs[j--]);
                }
            }
        }
        return sum;
    }
};