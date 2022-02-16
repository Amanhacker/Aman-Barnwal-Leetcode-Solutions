class MyStack {
public:
   
    queue<int> q1, q2;
    
    MyStack() {
    
        
    }
    
    void push(int x) {
        
        while(q2.empty() == false)                                  q2.pop();
        
        q2.push(x);
        
        // Now, push the all elements of q1
        while(q1.empty() == false) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Now, q2 becomes our stack
        q1 = q2;
        
        return;
    }
    
    int pop() {
        
        int top = q1.front();
        q1.pop();
        
        return top;
    }
    
    int top() {
        
        int top = q1.front();
        return top;
    }
    
    bool empty() {
        
        return (q1.empty() == true);
    }
                                                                                                                                                                                 
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */