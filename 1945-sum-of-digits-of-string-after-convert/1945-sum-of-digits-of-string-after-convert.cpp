class Solution {
public:
    
    int getLucky(string s, int k) {
    
        int n = s.length();
        string temp = "";
        
        // Replace the s[i] with its position in the alphabet, and then its sum
        for(int i=0; i<n; i++) {
            
            int t = (int)(s[i]) - 97 + 1;
            temp += (to_string)(t);
        }
        
        int sum;
        
        while(k--) {
            
            sum = 0;
            for(int i=0; i<temp.size(); i++)                sum += (int)(temp[i]) - 48;   
            
            temp = to_string(sum);
        }
        
        return sum;
    }
    
};