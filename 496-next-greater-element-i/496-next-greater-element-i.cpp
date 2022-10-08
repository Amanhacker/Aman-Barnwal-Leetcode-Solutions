class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& a1, vector<int>& a2) {
    
        vector<int> res;
        
        int n1 = a1.size();
        int n2 = a2.size();
        
        // Find the next greater element array of vector a2
        stack<int> w;
        vector<int> v2;             // NGR vector of a2 
        
        for(int i=n2-1; i>=0; i--) {
            
            if(w.empty() == true)           v2.push_back(-1);
            else if(w.top() >= a2[i])        v2.push_back(w.top());
            else if(w.top() < a2[i]) {
                
                while(w.empty() == false && w.top() < a2[i])         w.pop();
                
                if(w.empty() == true)       v2.push_back(-1);
                else                        v2.push_back(w.top());
            }
                
            w.push(a2[i]);
        }
        
        reverse(v2.begin(), v2.end());
        
        // Now, v2 contains NGR of array a2
        for(auto &x : a1) {
            
            // Find the index j in a2 where a2[j] = x
            auto it = find(a2.begin(), a2.end(), x);
            int ind = it - a2.begin();
            
            if(it != a2.end()) {
                res.push_back(v2[ind]);
            }
        }
        
        return res;
    }
    
};