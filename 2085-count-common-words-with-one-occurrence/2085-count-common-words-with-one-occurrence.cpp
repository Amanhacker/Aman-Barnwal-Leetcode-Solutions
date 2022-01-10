class Solution {
public:
    
    int countWords(vector<string>& words1, vector<string>& words2) {
    
        int count = 0;
        
        unordered_map<string, int> u1, u2;
        set<string> w;
        
        for(auto &x : words1) {
            w.insert(x);
            u1[x]++;            
        }   
        
        for(auto &x : words2) {
            w.insert(x);
            u2[x]++;  
        }                  
        
        for(auto &x : w) {
            if(u1[x] == 1 && u2[x] == 1)                        count++;
        }
        
        return count;
    }
    
};