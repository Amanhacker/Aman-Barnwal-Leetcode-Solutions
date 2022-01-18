class Solution {
public:

    // Using Backtracking
    
    void generateHelper(string temp, vector<string> &res, int n, int open, int close) {
        
        // Base Condition i.e n pairs
        if(temp.length() == n * 2) {
            
            res.push_back(temp);
            temp = "";
            
            return;
        }
        
        // Here, the idea is to only add '(' and ')' that we know will guarantee us a solution.
        
        // Once we add a '(' we will then discard it and try a ')' which can only close a valid '('. 
        // Each of these steps are recursively called.
        
        if(open < n)            generateHelper(temp + '(', res, n, open + 1, close);
        if(close < open)        generateHelper(temp + ')', res, n, open, close + 1);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        
        string temp = "";
        int open = 0, close = 0;
        
        generateHelper(temp, res, n, open, close);
        
        return res;
    }
    
};