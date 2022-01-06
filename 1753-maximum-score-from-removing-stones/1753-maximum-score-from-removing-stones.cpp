class Solution {
public:
    
    int maximumScore(int a, int b, int c) {
    
        int score = 0;
        
        // Form max heap
        priority_queue<int> pq;
        
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while(pq.empty() == false) {
            
            // When pq contains 0 or 1 element, break
            if(pq.size() <= 1)                              break;
            
            // Pop two elements and decrement 1 stone from each, and then push them back
            
            int t1 = pq.top();
            pq.pop();
            
            int t2 = pq.top();
            pq.pop();
            
            t1--;
            t2--;
            
            // Push them back to pq
            if(t1 >= 1)                                      pq.push(t1);
            if(t2 >= 1)                                      pq.push(t2);
            
            score++;
        } 
        
        return score;
    }
    
};