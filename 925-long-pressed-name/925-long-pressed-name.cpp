class Solution {
public:
    
    bool isLongPressedName(string name, string typed) {
    
        int n = name.length();
        int m = typed.length();
        
        for(int i=0, j=0; i < n && j < m; ) {
            
            if(name[i] == typed[j]) {

                int countInName = 1, countInTyped = 1;
                char ch = name[i];
                
                while(i + 1 < n && name[i] == name[i+1]) {
                    countInName++;
                    i++;
                }
                
                while(j + 1 < m && typed[j] == typed[j+1]) {
                    countInTyped++;
                    j++;
                }
                
                i++;
                j++;
                
                if(countInName > countInTyped)                                  return false;
                
                if(i == n && j < m)                                             return false;
                if(i < n && j == m)                                             return false;
            }
            
            else                                                                return false;
        }
        
        return true;
    }
    
};