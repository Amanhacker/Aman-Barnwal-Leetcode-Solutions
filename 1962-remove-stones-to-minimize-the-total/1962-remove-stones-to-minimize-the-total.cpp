class Solution {
public:
    
    int minStoneSum(vector<int>& piles, int k) {
        
        // Form max heap
        priority_queue<int> pq;
        
        for(auto &x : piles)                        pq.push(x);
        
        while(k-- && pq.empty() == false) {
            
            int temp = pq.top();
            pq.pop();
            
            int remStones = floor(temp / 2);
            pq.push(temp - remStones);
        }
        
        int res = 0;
        
        while(pq.empty() == false) {
            res += pq.top();
            pq.pop();
        }
        
        return res;
    }
    
};