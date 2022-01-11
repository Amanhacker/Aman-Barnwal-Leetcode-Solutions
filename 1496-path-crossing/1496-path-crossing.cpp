class Solution {
public:
    
    struct hash_pair {
        
        template <class T1, class T2>
        
        size_t operator() (const pair<T1, T2> &p) const {
            
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            
            return hash1 ^ hash2;
        }
    };
    
    bool isPathCrossing(string path) {
    
        // Possible movements : N, S, E, W
        // (0, 1), (0, -1), (1, 0), (-1, 0)
        
        int dx[4] = {0, 0,  1, -1};
        int dy[4] = {1, -1, 0,  0};
        
        int n = path.size();
        char dir[4] = {'N', 'S', 'E', 'W'};
        
        unordered_map<pair<int, int>, int, hash_pair> u;

        int x = 0, y = 0;
        u[{x, y}]++;
        
        for(int i=0; i<n; i++) {
            
            char ch = path[i];
            int indDir;
            
            if(ch == 'N')                           indDir = 0;
            else if(ch == 'S')                      indDir = 1;
            else if(ch == 'E')                      indDir = 2;
            else if(ch == 'W')                      indDir = 3;
            
            // Move in indDirection
            
            x += dx[indDir];
            y += dy[indDir];
            
            if(u[{x, y}] >= 1)                             return true;
            u[{x, y}]++;
        }
        
        return false;
    }
    
};