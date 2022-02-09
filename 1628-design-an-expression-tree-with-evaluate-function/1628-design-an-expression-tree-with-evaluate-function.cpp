/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class NumNode: public Node {
    
    public:
        
        NumNode(int val) : val(val) {};
        
        int evaluate() const {
            return val;
        };
    
    protected:
        
        int val;
};

class OpNode: public Node {
   
    public:
        
        OpNode(char op, Node *left, Node *right) : op(op), left(left), right(right) {};
        int evaluate() const;
    
    protected:
        
        char op;
        Node *left;
        Node *right;
};


int OpNode::evaluate() const {
   
    switch(this->op) {
       
        case '+':
            return left->evaluate() + right->evaluate(); 
        
        case '-':
            return left->evaluate() - right->evaluate(); 
        
        case '*':
            return left->evaluate() * right->evaluate(); 
        
        case '/':
            return left->evaluate() / right->evaluate(); 
        
        default:
            return 0;
    }
}

class TreeBuilder {
public:
    
    // Build the expression tree
    Node* buildTree(vector<string>& postfix) {
        
        stack<Node*> st;
        
        for (auto s: postfix) {
        
            if(isdigit(s[0])) {
            
                st.push(new NumNode(stoi(s)));
            }
            
            else{
            
                auto right = st.top();
                st.pop();
                
                auto left = st.top();
                st.pop();
                
                st.push(new OpNode(s[0], left, right));
            }
        }
        
        return st.top();
    }
    
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */