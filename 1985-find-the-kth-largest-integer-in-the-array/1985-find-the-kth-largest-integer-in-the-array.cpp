class Solution {
public:
    
    string kthLargestNumber(vector<string>& v, int k) {
    
        string res = "";
        
        // Form the Max Heap
        priority_queue<pair<int, string>> pq;                       // 1st arg - size of string, 2nd arg - string
        
        for(int i=0; i<v.size(); i++) {
            
            int len = v[i].size();
            string str = v[i];
            
            pq.push({len, str});
        }
        
        int i = 0;
        
        while(pq.empty() == false) {
            
            i++;
            
            if(i == k)                      break;
            pq.pop();
        }
        
        res = pq.top().second;
        return res;
    }
    
};