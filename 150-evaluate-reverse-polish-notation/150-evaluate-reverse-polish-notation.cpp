class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
    
        unordered_map<string, function<int (int, int) >> mp {
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };
        
        stack<int> st;
        
        for(auto &x : tokens) {
            
            // if it is not a char
            if(mp.count(x) == 0) {
                st.push(stoi(x));
            }
            
            // Else it is a character
            else {
                
                int t1 = st.top();
                st.pop();
                
                int t2 = st.top();
                st.pop();
                
                int temp = mp[x](t2, t1);
                st.push(temp);
            }
        }
        
        return st.top();
    }
    
};