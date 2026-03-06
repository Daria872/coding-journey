class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int>know(n,0);
        know[0]=1;
        know[firstPerson]=1;
        sort(meetings.begin(),meetings.end(),[](auto &a, auto&b){
            return a[2]<b[2];
        });
        int i=0;
        while(i<meetings.size()){
            int time=meetings[i][2];
            unordered_map<int,vector<int>>graph;
            unordered_set<int>people;
        //collect same time meetings
        while(i<meetings.size() && meetings[i][2]==time){
            int x=meetings[i][0];
            int y=meetings[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
            people.insert(x);
            people.insert(y);
            i++;
        }

        queue<int>q;
        //Start bfs from people who already know the secret
        for(auto p:people){
            if(know[p]) q.push(p);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int x:graph[curr]){
                if(!know[x]){
                    know[x]=1;
                    q.push(x);
                }
            }
        }
    }
    vector<int>res;
    for(int i=0;i<n;i++){
        if(know[i]){
            res.push_back(i);
        }
    }
    return res;
    }
};