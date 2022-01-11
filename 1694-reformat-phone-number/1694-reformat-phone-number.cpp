class Solution {
public:
    
    string reformatNumber(string number) {
    
        string res = "";
        
        string temp = "";
        int n = number.size();
        
        // Remove all spaces and dashes
        for(auto &x : number) {
            if(x != '-' && x != ' ')                                temp += x;
        }
        
        cout << temp << endl;
        
        // Now, group the digits in 2 or 3 digits with dashes in between
        
        if(temp.size() % 3 == 0) {
            
            int m = temp.size();
            
            // Group them in block of 3
            for(int i=0; i<m;) {
                
                if(i + 3 <= m) {
                   res += temp.substr(i, 3); 
                   i += 3;
                   if(i != m)                                       res += "-";
                } 
                else {
                    i = m;
                }
            }
        }
        
        else {
            
            // Group them in block of 2 and 3
            if(temp.size() == 2)                                    return temp;
            
            else if(temp.size() == 4) {
                res += temp.substr(0, 2) + "-" + temp.substr(2, 2);
            }
            
            else if(temp.size() >= 5) {
                
                int i;
                
                if((temp.size() - 2) % 3 == 0) {
                    // Then group them into blocks of 3 and 1 blocks of 2
                    for(i=0; i<temp.size()-2; i += 3) {
                        res += temp.substr(i, 3) + "-";
                    }
                    
                    res += temp.substr(i, 2);
                }
                
                else if((temp.size() - 4) % 3 == 0) {
                    // Then group them into blocks of 3 and 2 blocks of 2
                    for(i=0; i<temp.size()-4; i += 3) {
                        res += temp.substr(i, 3) + "-";
                    }
                    
                    res += temp.substr(i, 2) + "-" + temp.substr(i+2, 2);
                }
            }
        }
        
        return res;
    }
    
};