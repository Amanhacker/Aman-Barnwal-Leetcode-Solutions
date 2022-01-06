class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
    
        int n = mat.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto &x : mat) {
            for(auto &x1 : x)                       pq.push(x1);
        }
        
        int i = 0;
        
        while(pq.empty() == false) {
            
            i++;
            
            if(i == k)                              break;
            pq.pop();
        }
        
        return pq.top();
    }
    
};