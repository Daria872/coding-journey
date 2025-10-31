class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest=INT_MAX,ssmallest=INT_MAX;
        for(int price:prices){
            if(price<smallest){
                ssmallest=smallest;
                smallest=price;
            }
            else if(price<ssmallest){
                ssmallest=price;
            }
        }
        if((smallest+ssmallest)>money){
            return money;
        }
        return money-(smallest+ssmallest);
    }
};