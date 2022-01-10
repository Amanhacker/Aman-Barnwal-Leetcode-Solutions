class Solution {
public:
    
    int hammingDistance(int x, int y) {
    
        int count = 0;
        
        vector<int> res1(32, 0), res2(32, 0);
        int ind = 31;
        
        while(x > 0) {
            
            res1[ind] = (x % 2);
            ind--;
            
            x = x / 2;
        }
        
        ind = 31;
        
        while(y > 0) {
            
            res2[ind] = (y % 2);
            ind--;
            
            y = y / 2;
        }
        
        for(int i=0; i<32; i++) {
            if(res1[i] != res2[i])                              count++;
        }
        
        return count;
    }
    
};