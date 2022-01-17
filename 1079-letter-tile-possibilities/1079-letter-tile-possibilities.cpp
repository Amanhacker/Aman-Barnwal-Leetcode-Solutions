class Solution {
public:
    
    void findAllPermutations(string tiles, int n, string temp, unordered_map<char, int> &vis, unordered_map<string, int> &u, int &count) {

        // Base Condition
        if(temp != "" && u[temp] == 0) {
            count++;
            u[temp] = 1;
        }   

        // Run for loop from 0 to (n - 1) and checks if it is not visited
        for(int i=0; i<=n-1; i++) {

            char w = tiles[i];

            // Here it's better to use index for visited array because element in array could be duplicates
            if(vis[i] == 0) {

                vis[i] = 1;
                temp += w;

                findAllPermutations(tiles, n, temp, vis, u, count);

                // Make it unvisited and pop it out from vector while backtracking
                vis[i] = 0;
                temp.erase(temp.begin() + temp.size() - 1);
            }
        }

        return;
    }
    
    int numTilePossibilities(string tiles) {
    
        int count = 0;
        int n = tiles.length();
        
        string temp = "";
    
        unordered_map<char, int> vis;
        unordered_map<string, int> u;
        
        findAllPermutations(tiles, n, temp, vis, u, count);
        
        return count;
    }
    
};