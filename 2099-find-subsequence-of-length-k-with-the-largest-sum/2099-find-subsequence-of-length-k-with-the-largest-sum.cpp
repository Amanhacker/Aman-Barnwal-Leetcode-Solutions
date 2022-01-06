class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& a, int k) {
    
        vector<int> res;
        
        // Our moto is to put the k largest element in pq of size k, where bottom being the greatest
        
        // Form Min heap
        using pi = pair<int, int>;                               // 1st arg - element, 2nd arg - index
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        for(int i=0; i<a.size(); i++) {
            pq.push({a[i], i});
            if(pq.size() > k)                       pq.pop();
        }
        
        // Order should not change
        vector<pi> temp;                            // 1st arg - index, 2nd arg - element
        
        while(pq.empty() == false) {
            temp.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }
        
        // sort according to indexes
        sort(temp.begin(), temp.end());
        
        for(auto &x : temp)                         res.push_back(x.second);
        return res;
    }
    
};