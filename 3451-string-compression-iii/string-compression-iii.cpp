class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        int i=0;
        string comp;
        while(i<n){
            int count=0;
            char ch=word[i];
            while(i<n && count<9 && ch==word[i]){
                count++;
                i++;
            }
            comp+=to_string(count)+ch;
        }
        return comp;
    }
};