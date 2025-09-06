class Solution {
public:
    int getmax(const std::vector<int>&freq){
        int maxfreq=INT_MIN;
        for(int count:freq){
            maxfreq=std::max(maxfreq,count);
        }
        return maxfreq;
    }
    int getmin(const std::vector<int>&freq){
        int minfreq=INT_MAX;
        for(int count:freq){
            if(count>0)
            minfreq=std::min(minfreq,count);
        }
        return minfreq;
    }
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            std::vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int beauty=getmax(freq)-getmin(freq);
                sum+=beauty;
            }
        }
        return sum;
    }
};