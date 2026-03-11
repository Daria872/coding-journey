class Solution {
public:
    typedef pair<char,int>P;

    struct lambda{
        bool operator()(P&P1, P&P2){
            return P1.second<P2.second;
        }
    };

    string frequencySort(string s) {

        priority_queue<P,vector<P>,lambda>pq;
        unordered_map<char,int>mpp;
        for(char &ch:s){
            mpp[ch]++;
        }

        for(auto it:mpp){
            pq.push({it.first,it.second});
        }

        string res="";
        while(!pq.empty()){
            P temp=pq.top();
            pq.pop();
            res+=string(temp.second,temp.first);
        }

        return res;
    }
};