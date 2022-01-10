class Solution {
public:
    
    int countPoints(string rings) {
    
        int count = 0;
        unordered_map<int,set<int>> u;
        
        for(int i=0; i<rings.size(); i += 2) {
            
            char ch = rings[i];
            int pos = rings[i + 1];
            
            u[pos].insert(ch);
        }
        
        for(auto &x : u) {
            set<int> temp = x.second;
            if(temp.size() == 3)                                count++;
        }
        
        return count;
    }
    
    
};