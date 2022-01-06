class Solution {
public:
    
    bool carPooling(vector<vector<int>>& trips, int cap) {
    
        int n = trips.size();
        using pi = pair<int, int>;                          // 1st arg - location, 2nd arg - no.of persons
            
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        unordered_map<int, int> u;                          // 1st arg - location, 2nd arg - no.of persons at this location
        
        for(auto &x : trips) {
            
            int from = x[1];
            int to = x[2];
            
            for(int i=from; i<to; i++)                     u[i] += x[0];
        }
        
        for(auto &x : u)                                    pq.push({x.first, x.second});
        
        while(pq.empty() == false) {
            
            pi temp = pq.top();
            pq.pop();
            
            if(temp.second > cap)                           return false;
        }
        
        return true;
    }
    
};