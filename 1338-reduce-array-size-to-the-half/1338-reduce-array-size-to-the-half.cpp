class Solution {
public:
    
    int minSetSize(vector<int>& v) {
        
        int res = 0;
        int n = v.size();
        
        // Form Max Heap
        priority_queue<pair<int,int>> pq;       // 1st arg - freq, 2nd arg - ele
        unordered_map<int, int> u;              // 1st arg - element, 2nd arg - freq
        
        for(auto &x : v)                        u[x]++;
        
        for(auto &x : u) {
            pq.push({x.second, x.first});
        }
        
        int removedCount = 0;
        
        while(pq.empty() == false) {
            
            if(removedCount >= n/2)             break;
            
            int freq = pq.top().first;
            pq.pop();
            
            removedCount += freq;
            res++;
        }
        
        return res;
    }
    
};