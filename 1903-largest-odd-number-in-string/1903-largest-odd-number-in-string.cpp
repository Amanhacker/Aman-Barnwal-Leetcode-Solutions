class Solution {
public:
    
    string largestOddNumber(string num) {
    
        string res = "";
        int n = num.length();
        
        // It should be substring
        
        int oddIndex = -1;
        
        for(int i=n-1; i>=0; i--) {
            
            int x = (int)(num[i]) - 48;
            
            if(x % 2 == 1) {
                oddIndex = i;
                break;
            }
        }

        if(oddIndex == -1)                                      return res;
        
        // Substring is from [0, oddIndex]
        
        res = num.substr(0, oddIndex + 1);
        return res;
    }
    
};