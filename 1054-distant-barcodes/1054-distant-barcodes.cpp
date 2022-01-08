class Solution {
public:
    
    vector<int> rearrangeBarcodes(vector<int>& v) {
    
        vector<int> res;
        
        int n = v.size();
        priority_queue<pair<int, int>> pq;          // 1st arg - Freq, 2nd arg - Element
        
        unordered_map<int, int> u;                  // 1st arg - Element, 2nd arg - Freq
        
        for(auto &x : v)                            u[x]++;
        for(auto &x : u)                            pq.push({x.second, x.first});
        
        pair<int, int> prevEle = pq.top();
        pq.pop();
        
        int prev = prevEle.second;
        int prevFreq = prevEle.first;
        
        res.push_back(prev);

        if(prevFreq >= 2)                              pq.push({prevFreq - 1, prev});
        
        while(pq.empty() == false) {
            
            pair<int, int> temp = pq.top();
            pq.pop();
            
            if(prev != temp.second) {
                
                res.push_back(temp.second);
            
                int freq = temp.first;
                if(freq >= 2)                           pq.push({freq - 1, temp.second});
                
                prev = temp.second;
            }
            
            else if(prev == temp.second){
                
                // Pop the first two max occuring element, and decrease the freq by 1 of 2nd most frequent element
                if(pq.size() >= 1) {
                    
                    pair<int, int> tempSecond = pq.top();
                    pq.pop();
                    
                    int freq2 = tempSecond.first;
                    int ele = tempSecond.second;
                    
                    res.push_back(ele);
                    prev = ele;
                    
                   if(freq2 >= 2)                           pq.push({freq2 - 1, ele});
                
                    // Also, push the 1st temp
                    pq.push(temp);
                }
                
                
            }
           
        }
        
        return res;
    }
    
};