class Solution {
public:
    
    bool canPlaceFlowers(vector<int>& v, int n) {
    
        int count = 0;
        
        if(v.size() == 1) {
            if(v[0] == 0)                                  return (n <= 1);
            else if(v[0] == 1)                             return (n == 0);                                  
        }
        
        int i = 0;
        
        if(v[0] == 0) {
            
            int noZeroes = 0;
                
            while(i < v.size() && v[i] == 0) {
                noZeroes++;
                i++;
            }   

            // Next adjacent character after zeroes are ended
            // Now, v[i] = 1

            if(i == v.size())                               return ( (noZeroes + 1) / 2 >= n);
            else                                            count += (noZeroes / 2);
        }
        
        if(i == v.size())                                   return (count >= n);
        
        for( ; i<v.size(); i++) {
            
            if(v[i] == 1)                                   continue;
            
            if(v[i] == 0) {
                
                int noZeroes = 0;
                
                while(i < v.size() && v[i] == 0) {
                    noZeroes++;
                    i++;
                }   
                
                // Next adjacent character after zeroes are ended
                // Now, v[i] = 1
                
                if(i == v.size()) {
                    
                    count += noZeroes / 2;
                    return (count >= n);
                }   
                
                if(noZeroes % 2 == 1)                       count += (noZeroes / 2);
                else                                        count += (noZeroes - 1) / 2;
                
                i--;
            }
        }
        
        return (count >= n);
    }
    
};