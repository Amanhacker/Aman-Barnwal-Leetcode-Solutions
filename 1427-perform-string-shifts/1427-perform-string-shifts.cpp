class Solution {
public:
    
    // In-place rotates s towards left by d
    void leftRotate(string &s, int d) {
        
        reverse(s.begin(), s.begin() + d);
        reverse(s.begin() + d, s.end());
        
        reverse(s.begin(), s.end());
        
        return;
    }

    // In-place rotates s towards right by d
    void rightRotate(string &s, int d) {
       
        leftRotate(s, s.length() - d);
        
        return;
    }
    
    string stringShift(string s, vector<vector<int>>& shift) {
    
        string res = "";
        int n = s.length();

        int l = 0;
        
        for(auto &x : shift) {
            
            int dir = x[0];
            int amt = x[1];
            
            // Shift the string s in dir direction by "amt" amount
            if(dir == 0)                                            l += amt;
            else if(dir == 1)                                       l -= amt;
        }
        
        res += s;
        
        // if left is -ve, then rotate the string by "l" right direction
        
        
        // Rotate the string right-shift by l amount
        if(l > 0)                                                   leftRotate(res, l % n);         
        
        // Rotate the string left-shift by l amount
        else                                                        rightRotate(res, -l % n);
            
        return res;
    }
    
};