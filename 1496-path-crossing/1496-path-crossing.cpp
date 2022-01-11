class Solution {
public:
    
    bool isPathCrossing(string path) {
    
        int n = path.size();
        set<pair<int, int>> w;

        int x = 0, y = 0;
        w.insert({0, 0});
        
        for(int i=0; i<n; i++) {
            
            char ch = path[i];
            
            if(ch == 'N')                           y++;
            else if(ch == 'S')                      y--;
            else if(ch == 'E')                      x++;
            else if(ch == 'W')                      x--;
            
            if(w.find({x, y}) != w.end())           return true;
            w.insert({x, y});
        }
        
        return false;
    }
    
};