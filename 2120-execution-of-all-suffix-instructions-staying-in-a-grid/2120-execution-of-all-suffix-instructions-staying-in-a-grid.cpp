class Solution {
public:
    
    // L, R, U, D
    // (0, -1), (0, 1), (-1, 0), (1, 0)
    
    int dx[4] = { 0, 0, -1, 1};
    int dy[4] = {-1, 1,  0, 0};
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    
        vector<int> res;
        int siz = s.length();
        
        for(int i=0; i<siz; i++) {
            
            vector<int> sP = startPos;
            int count = 0;
            
            // Movement starts from ith index of string
            for(int j=i; j<siz; j++) {
                
                int k;
                
                if(s[j] == 'L')                         k = 0;
                else if(s[j] == 'R')                    k = 1;
                else if(s[j] == 'U')                    k = 2;
                else if(s[j] == 'D')                    k = 3;
                
                int x1 = sP[0] + dx[k];
                int y1 = sP[1] + dy[k];
                
                
                if(x1 >=0 && x1 < n && y1 >=0 && y1 < n) {
                    
                    count++;
                    
                    // Update startPos
                    sP[0] = x1;
                    sP[1] = y1;
                }               

                else                                                    j = siz;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
    
};