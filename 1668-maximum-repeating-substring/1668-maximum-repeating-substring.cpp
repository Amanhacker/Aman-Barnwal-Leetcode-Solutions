class Solution {
public:
    
    int maxRepeating(string seq, string word) {
    
        int res = 0;
        string temp = "";
        
        while(true) {
            
            temp += word;
            
            // Check whether temp is not a substring in sequence
            if(seq.find(temp) == string :: npos)                       return res;
            res++;
        }
        
        return res;        
    }
    
};