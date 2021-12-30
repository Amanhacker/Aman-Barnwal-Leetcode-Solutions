class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> res;
        
        unordered_map<string, int> uMap;
        unordered_map<string, vector<pair<string, double>>> adj;
        
        for(int i=0; i<equations.size(); i++) {
            
            string u = equations[i][0];
            string v = equations[i][1];
            
            uMap[u]++;
            uMap[v]++;

            double wt = values[i];
            double wtReverse = 1 / wt;
            
            // Edge u -> v has weight wt, and edge v -> u has weight (1 / wt)
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wtReverse});
        }
        
        
        // Using Dijkstra Algorithm
        
        // Max Heap
        priority_queue<pair<double, string>> pq;
        unordered_map<string, double> dist;
        
        for(int k=0; k<queries.size(); k++) {
            
            string src  = queries[k][0];
            string dest = queries[k][1];
            
            dist.clear();
            while(pq.empty() == false)                                                      pq.pop();
            
            // if either src or dest is not found in uMap then return -1.0
            if(uMap[src] == 0 || uMap[dest] == 0) {
                res.push_back(-1.0);                
            }   
            
            else {
                
                 pq.push({1.0, src});
            
                 while(pq.empty() == false) {

                    pair<double, string> cur = pq.top();
                    pq.pop();

                    string cur_node = cur.second;
                    double cur_wt = cur.first;

                    for(int i=0; i<adj[cur_node].size(); i++) {

                        pair<string, double> w = adj[cur_node][i];

                        string w_node = w.first;
                        double w_wt = w.second;

                        if(dist[w_node] < cur_wt * w_wt) {
                            dist[w_node] = cur_wt * w_wt;
                            pq.push({dist[w_node], w_node});
                        }
                    }
                }
                
                if(dist[dest] != 0.0)                                                           res.push_back(dist[dest]);
                else                                                                            res.push_back(-1.0);
            }
        }
        
        return res;
    }
    
};