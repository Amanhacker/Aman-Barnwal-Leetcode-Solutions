class Solution {
public:
   
    bool isValidSerialization(string preorder) {
    
        stringstream ss(preorder);
        
        string cur;
        int c = 1;          // Starts with c = 1
        
        // Traversing a node for the first time - Add (-1)
        // Traversing a Non-null node - Add 2
        
        while(getline(ss, cur, ',')) {
            
            // Since, we are traversing cur for the first time, so reduce 1
            c--;
            
            if(c < 0)                           return false;
            
            if(cur != "#")                      c += 2;
        }
        
        return (c == 0);
    }
    
};