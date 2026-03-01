class Solution {
public:
    // TC: O(N), SC: O(1)
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else{// 20
                if(ten && five){
                    ten--;
                    five--;
                }
                else if(five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};