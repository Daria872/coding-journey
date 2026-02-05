class Solution {
public:
    int maximum69Number (int num) {
        //since atmost 1 number can be replaced; in order to maximise the number replace the first 6 with 9
        string dig=to_string(num);
        for(int i=0;i<dig.size();i++){
            if(dig[i]=='6'){
                dig[i]='9';
                break;
            }
        }
        int number=stoi(dig);
        return number;
    }
};