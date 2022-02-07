class Solution {
public:
    
    int findFinalValue(vector<int>& a, int orig) {
    
        int n = a.size();
        
        while(true) {

            auto it = find(a.begin(), a.end(), orig);
    
            if(it != a.end())                       orig *= 2;
            else                                    break;
        }
        
        return orig;
    }
    
};