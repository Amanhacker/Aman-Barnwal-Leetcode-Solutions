class MaxStack {
public:
  
    stack<int> s;
    
    MaxStack() {
        
    }
    
    void push(int x) {
        
        s.push(x);
        return;
    }
    
    int pop() {
        
        int top = s.top();
        s.pop();
        
        return top;
    }
    
    int top() {
        
        return s.top();        
    }
    
    // Retrieves the maximum element without removing it
    int peekMax() {
        
        stack<int> st = s;
        int maxi = INT_MIN;
        
        while(st.empty() == false) {
            
            int top = st.top();
            maxi = max(maxi, top);
            
            st.pop();
        }
        
        return maxi;
    }
    
    // Retrieves the maximum element in the stack and removes it.
    int popMax() {
        
        stack<int> st = s;
        vector<int> v;
        
        int maxi = INT_MIN;
        
        while(st.empty() == false) {
            
            int top = st.top();
            v.push_back(top);
            
            maxi = max(maxi, top);
            st.pop();
        }
        
        for(int i=0; i<v.size(); i++) {
            if(v[i] == maxi) {
                v.erase(v.begin() + i);
                break;
            }
        }
        
        reverse(v.begin(), v.end());
        
        while(s.empty() == false)                       s.pop();
        
        for(auto &x : v)                                s.push(x);
        
        return maxi;
    }
    
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */