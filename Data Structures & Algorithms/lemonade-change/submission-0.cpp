class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> amount(3,0);
        for(int i=0;i<bills.size();i++) {
            if(bills[i]==5) {
                amount[0]++;
            }
            else if(bills[i]==10) {
                if(amount[0]==0) return false;
                amount[0]--;
                amount[1]++; 
            }
            else {
                if(amount[0]>0 && amount[1]>0) {
                    amount[0]--;
                    amount[1]--;
                    amount[2]++;
                }
                else if(amount[0]>2) {
                    amount[0] -= 3;
                    amount[2]++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};