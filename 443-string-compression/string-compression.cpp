class Solution {
public:
    int compress(vector<char>& chars) {
        int indx=0;
        for(int i=0;i<chars.size();i++){
            int count=0, ch=chars[i];
            while(i<chars.size() && ch==chars[i]){
                count++;
                i++;
            }
            if(count==1) {
                chars[indx++]=ch;
            }
            else{
                chars[indx++]=ch;
                string str=to_string(count);
                for(char dig:str){
                    chars[indx++]=dig;
                }
            }
            i--;
        }
        chars.resize(indx);
        return indx;
    }
};