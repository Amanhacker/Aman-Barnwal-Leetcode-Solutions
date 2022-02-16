class MyQueue {
public:
    
    stack<int> s1, s2;
    
    MyQueue() {
    
        
    }
    
    void push(int x) {
        
        while(s2.empty() == false)                          s2.pop();
        
        // Push all the elements form s1 to s2
        while(s1.empty() == false) {
            s2.push(s1.top());
            s1.pop();
        }
        
        // Now, push the element x into stack s2
        s2.push(x);
        
        // Now, copy all the elements from s2 to s1
        
        while(s2.empty() == false) {
            s1.push(s2.top());
            s2.pop();
        }
        
        return;
    }
    
    int pop() {
        
        int top = s1.top();
        s1.pop();
        
        return top;
    }
    
    int peek() {
        
        int top = s1.top();
        return top;
    }
    
    bool empty() {
        
        return (s1.size() == 0);
    }
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */