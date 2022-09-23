class Solution {
public:
    
    vector<int> nextGreaterElements(vector<int>& a) {
    
        vector<int> res;
        int n = a.size();
        
        if(n == 0)                          return res;
        
        stack<int> w;
        
        while(w.empty() == false)           w.pop();

        // Start from last index
        for(int i=n-1; i>=0; i--) {
            
            if(w.empty() == true) {
                
                for(int k=n-2; k>=0; k--)   w.push(a[k]);
                
                // Pop out all elements which is less than a[0]
                while(w.empty() == false && w.top() <= a[i])         w.pop();
                
                if(w.empty() == true)       res.push_back(-1);
                else                        res.push_back(w.top());
                
            }   
            
            else if(w.top() > a[i])         res.push_back(w.top());
            else if(w.top() <= a[i]) {
                
                // Pop all elements from stack which is less than a[i]
                while(w.empty() == false && w.top() <= a[i])     w.pop();
                
                if(w.empty() == true)       res.push_back(-1);
                else                        res.push_back(w.top());
            }
            
            w.push(a[i]);
        }
        
        // Now, reverse the vector
        reverse(res.begin(), res.end());

        return res;
    }
    
};