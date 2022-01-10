class CustomStack {
public:
    
    stack<int> w;
    int maxS;
    
    CustomStack(int maxSize) {
        maxS = maxSize;    
    }
    
    void push(int x) {
        
        if(w.size() < maxS)                     w.push(x);
        return;
    }
    
    int pop() {
        
        if(w.empty() == true)                   return -1;
        else {
            
            int top = w.top();
            w.pop();
            
            return top;
        }
        
    }
    
    void increment(int k, int val) {
        
        vector<int> temp;
        int n = w.size();
        
        while(w.empty() == false) {
            temp.push_back(w.top());
            w.pop();
        }
        
        if(n < k) {
            // Increments all the elements of vector by val
            for(int i=0; i<n; i++)                       temp[i] += val;
        }
        
        else {
            // Increment last k elements of vector by val
            for(int i=n-1; i>=n-k; i--)               temp[i] += val;
        }
        
        // Push the elements into stack from end
        for(int i=temp.size()-1; i>=0; i--) {
            w.push(temp[i]);
        }
        
        return;
    }
    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */