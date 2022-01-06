class Solution {
public:
    
    vector<string> findRelativeRanks(vector<int>& score) {
    
        int n = score.size();
        vector<string> res(n);
        
        // Form max heap
        priority_queue<pair<int, int>> pq;                       // 1st arg - Element, 2nd arg - index
        
        for(int i=0; i<score.size(); i++)                        pq.push({score[i], i});
        
        int i = 1;
        
        while(pq.empty() == false) {
            
            pair<int, int> temp = pq.top();
            pq.pop();
            
            int sc = temp.first;
            int index = temp.second;
            
            if(i == 1)                                           res[index] = "Gold Medal";
            else if(i == 2)                                      res[index] = "Silver Medal";
            else if(i == 3)                                      res[index] = "Bronze Medal";
            else                                                 res[index] = to_string(i);
            
            i++;
        }
        
        
        return res;
    }
    
};