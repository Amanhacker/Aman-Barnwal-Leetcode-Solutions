class Solution {
public:
    
    int minimumSum(int num) {
    
        int res = 0;
        
        // Split num into min two numbers
        
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        res += ( 10 * ( (s[0] - '0') + (s[1] - '0') ) ) + ( (s[2] - '0') + (s[3] - '0') );
        return res;
    }
    
};