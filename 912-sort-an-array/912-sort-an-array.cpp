class Solution {
public:
    
    vector<int> sortArray(vector<int>& a) {
        
        vector<int> res;
        
        // Form Min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &x : a)                pq.push(x);
        
        while(pq.empty() == false) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
    
};