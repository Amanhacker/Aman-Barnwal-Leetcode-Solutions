class Solution {
public:
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    
        // Form a graph
        vector<vector<int>> adj(n);
        int e = 0;
        
        vector<int> indegree(n, 0);
        
        for(int i=0; i<n; i++) {
            
            if(leftChild[i] != -1) {
                
                // Edge from i-> leftChild[i]
                adj[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                
                e++;
            }   
            
            if(rightChild[i] != -1) {
                
                // Edge from i-> rightChild[i]
                adj[i].push_back(rightChild[i]);                
                indegree[rightChild[i]]++;
                
                e++;
            }   
        }
        
        // In graph, it will be binary valid tree, if and only if, the indegree of a node <= 1, and no cycle, and e == n-1

        if(e < n-1)                                            return false;
        
        queue<int> q; 
        vector<int> vis(n, 0); 
        
        int c = 0; 
        
//         for(int i = 0; i < adj.size(); i++) { 
//             for(int j = 0; j < adj[i].size(); j++) { 
//                 indegree[adj[i][j]]++;
//             }
//         } 
        
        for(int i=0; i<indegree.size(); i++) {  
            
            // Node should have either either 0 or 1 as its indegree
            
            if(indegree[i] > 1)                             return false;

            else if(indegree[i] == 0) { 
                q.push(i); 
                c++;
            }
        } 
        
        // Using Topological Sort
        
        while(q.empty() == false) { 
            
            int temp = q.front(); 
            q.pop(); 
            
            vis[temp] = 1;
            
            for(int i=0; i<adj[temp].size(); i++) { 
                
                int child = adj[temp][i];
                indegree[child]--;
                
                if(vis[child] == 0 && indegree[child] == 0) { 
                    q.push(child); 
                    c++;
                }
            }
        } 
        
        // If cycles are present or if e != n-1, then return false
        
        if(c != n || e != n-1)                             return false;
        
        return true;
    }
    
};