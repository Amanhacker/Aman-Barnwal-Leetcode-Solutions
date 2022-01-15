class Solution {
public:
    
    bool rotateString(string s, string goal) {
    
        int n1 = s.length();
        int n2 = goal.length();
        
        if(n1 != n2)                                   return false;
        if(n1 == 0)                                    return true;
        
        string temp = s + s;
        
        // Check whether goal is a subtring of temp
        if(temp.find(goal) != string::npos)            return true;
        
        return false;
    }
    
};