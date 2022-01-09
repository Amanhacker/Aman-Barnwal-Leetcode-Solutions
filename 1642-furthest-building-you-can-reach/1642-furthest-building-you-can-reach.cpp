class Solution {
public:
    
    // Using Min Heap
    
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
    
        int n = h.size();
        
        // Using Min Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0;
        
        while(i < n - 1 && pq.size() < ladders) {
            
            int jumpHeight = h[i + 1] - h[i];
            
            if(jumpHeight > 0)                              pq.push(jumpHeight);
            i++;
        }
        
        while(i < n - 1) {
            
            int jumpHeight = h[i + 1] - h[i];
            
            if(jumpHeight > 0) {
               
                if(pq.empty() == false && jumpHeight > pq.top()) {
                
                    // We here found a larger current jump, so use ladder for this
                    bricks -= pq.top();
                    pq.pop();

                    pq.push(jumpHeight);
                }

                else                                        bricks -= jumpHeight;
            }
            
            if(bricks < 0)                                  return i;
            i++;
        }
        
        return i;
    }
    
};
