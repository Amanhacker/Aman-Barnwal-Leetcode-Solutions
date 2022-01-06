class Solution {
public:
    
    int lastStoneWeight(vector<int>& v) {
    
        // Form Max Heap
        priority_queue<int> pq;
        int n = v.size();
        
        for(auto &x : v)                            pq.push(x);
        
        while(pq.empty() == false) {
            
            if(pq.size() == 1)                      return pq.top();
            
            int t1 = pq.top();
            pq.pop();
            
            int t2 = pq.top();
            pq.pop();
            
            if(t1 != t2)                            pq.push(abs(t1 - t2));
        }
        
        return 0;
    }
    
};