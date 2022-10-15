class Solution {
public:
   
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    
        long long score = 0;
        unordered_map<int, vector<int>> adj;
        
        vector<int> degree(n, 0);
        
        for(auto &x : roads) {
            
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            
            degree[x[0]]++;
            degree[x[1]]++;
        }        
        
        // Assign a number from [1, n] to each city
        
        // 1st arg - degree, 2nd arg - city
        vector<pair<int, int>> nodes;
        
        for(int i=0; i<n; i++) {
            nodes.push_back({degree[i], i});    
        }
        
        // Sorting the cities in order of decreasing degrees
        sort(nodes.begin(), nodes.end(), greater<pair<int, int>>());
        
        vector<int> importance(n, 0);
        int k = n;
        
        for(int i=0; i<n; i++) {
            int curCity = nodes[i].second;
            importance[curCity] = k--;
        }
        
        for(auto &x : roads) {
            score += importance[x[0]] + importance[x[1]];
        }
        
        return score;
    }
    
};