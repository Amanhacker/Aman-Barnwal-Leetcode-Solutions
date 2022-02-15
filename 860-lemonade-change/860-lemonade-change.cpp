class Solution {
public:

    bool lemonadeChange(vector<int>& bills) {
    
        int n = bills.size();
        map<int, int> mp;
        
        for(auto &x : bills) {
            
            // He needs to give (x - 5) change to the customer
            int change = (x - 5);
            
            if(change > 0) {
               
                if(change % 10 == 0) {

                    if(mp[10] >= change / 10) {
                        mp[10] -= change / 10;
                        change -= 10 * (change / 10);
                    }                         

                    if(mp[5] >= change / 5) {
                        mp[5] -= change / 5;
                        change -= 5 * (change / 5);
                    }

                    if(change > 0)                                 return false;
                }

                else {
                        
                    if(change >= 10 && mp[10] >= change / 10) {
                        mp[10] -= change / 10;
                        change -= 10 * (change / 10);
                    }   

                    if(change >= 5 && mp[5] >= change / 5) {
                        mp[5] -= change / 5;
                        change -= 5 * (change / 5);
                    }   

                    if(change > 0)                                  return false;
                }                                            
            }
            
            mp[x]++;
        }
        
        return true;
    }
    
};