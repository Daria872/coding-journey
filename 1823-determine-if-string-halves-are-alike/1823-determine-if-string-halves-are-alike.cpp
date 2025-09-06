class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='i' || ch=='U' || ch=='u')
        return true;
        else
        return false;
    }
    bool halvesAreAlike(string s) {
        int n=s.size(),mid=n/2;
        int i=0,j=mid;
        int count_f=0,count_s=0;
        while(i<mid && j<n){
            if(isVowel(s[i])) count_f++;
            if(isVowel(s[j])) count_s++;
            i++;
            j++;
        }
        return (count_f==count_s);
    }
};