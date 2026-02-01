class Solution {
public:
    string reverseByType(string s) {
        vector<int>alpha,special;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                alpha.push_back(i);
            }
            else{
                special.push_back(i);
            }
        }
        int st1=0,end1=alpha.size()-1;
        while(st1<end1){
            swap(s[alpha[st1]],s[alpha[end1]]);
            st1++;
            end1--;
        }
        int st2=0,end2=special.size()-1;
        while(st2<end2){
            swap(s[special[st2]],s[special[end2]]);
            st2++;
            end2--;
        }
        return s;
    }
};