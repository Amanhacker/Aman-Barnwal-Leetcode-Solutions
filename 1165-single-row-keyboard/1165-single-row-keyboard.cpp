class Solution {
public:
  
    int calculateTime(string keyboard, string word) {
    
        int res = 0;
        
        int pre = -1;
        
        for(int i=0; i<word.length(); i++) {
            
            int ind = find(keyboard.begin(), keyboard.end(), word[i]) - keyboard.begin();
            
            if(pre == -1)                                       res += ind;
            else                                                res += abs(ind - pre);
            
            pre = ind;
        }
        
        return res;
    }
    
};