class Solution {
public:
    
    int countWords(vector<string>& words1, vector<string>& words2) {
    
        int count = 0;
        unordered_map<string, int> u1, u2;
        
        for(auto &x : words1)                           u1[x]++;          
        for(auto &x : words2)                           u2[x]++;  
        
        for(auto &x : u1) {
            if(x.second == 1 && u2[x.first] == 1)       count++;
        }
        
        return count;
    }
    
};