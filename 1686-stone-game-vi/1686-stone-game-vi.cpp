class Solution {
public:
    
    int stoneGameVI(vector<int>& aliceVal, vector<int>& bobVal) {
    
        int n = aliceVal.size();
        
        int sumAl = 0;
        int sumBob = 0;
        
        // Alice starts first
        
        // Form a Max Heap
        priority_queue<pair<int, int> > pq;
        vector<int> vis(n, 0);
        
        // Greedily choose the max of Alice[i] + Bob[i] first
        
        for(int i=0; i<n; i++) {
            pq.push({aliceVal[i] + bobVal[i], i});
        }
        
        // Starting with Alice first
        int i = 0;                              // If i is even, then Alice turn, else Bob's turn
        
        while(pq.empty() == false) {
            
            pair<int, int> temp = pq.top();
            pq.pop();
            
            int ind = temp.second;
            
            if(vis[ind] == 0) {
               
                
                // Make that index visited
                vis[ind] = 1;
                
                if(i % 2 == 0)                              sumAl  += aliceVal[ind];
                else                                        sumBob += bobVal[ind];
            }
            
            i++;
        }
        
    
        if(sumAl > sumBob)                                  return 1;
        else if(sumAl < sumBob)                             return -1;
        else                                                return 0;
    }
    
    
};