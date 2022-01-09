class Solution {
public:
    
    int minSwaps(string s) {
    
        int n = s.length();
        int swaps = 0, balance = 0, j = n - 1;
        
        for(int i=0; i<n; i++) {
            
            if(s[i] == '[')                                 balance++;
            else                                            balance--;
            
            if(balance < 0) {
                
                // Swap the ']' with last occuring '['
                
                while(i < j && s[j] != '[')                 j--;
                
                swap(s[i], s[j]);
                swaps++;
                
                balance = 1;
            }
        }
        
        return swaps;
    }
    
};

