class Solution {
public:
    
    int numberOfBeams(vector<string>& bank) {
    
        int sum = 0;
        int n = bank.size();
        
        if(n == 1)                                                  return 0;
        
        vector<int> laserBeamsRowwise;
       
        int firstIndex;
        bool flag = true;
        
        for(int i=0; i<n; i++) {
            
            string temp = bank[i];
            
            int c = count(temp.begin(), temp.end(), '1');
            
            if(c > 0 && flag) {
                firstIndex = i;
                flag = false;
            }                
            
            laserBeamsRowwise.push_back(c);
        }
        
        if(flag == true)                                            return 0;
        
        int w = laserBeamsRowwise[firstIndex];
        
        for(int i=firstIndex + 1; i<n; i++) {
            
            if(laserBeamsRowwise[i] > 0) {
                
                sum += (w * laserBeamsRowwise[i]);
                
                // Update w
                w = laserBeamsRowwise[i];
            }
        }
        
        return sum;
    }
    
};