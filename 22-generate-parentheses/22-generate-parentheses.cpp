class Solution {
public:

    // Using Recursion
    
    void generateHelper(string temp, vector<string> &res, int n, int noOpenB, int noCloseB) {
        
        // Base Condition i.e n pairs
        if(temp.length() == n * 2) {
            
            res.push_back(temp);
            temp = "";
            
            return;
        }
        
        // Here, the idea is to only add '(' and ')' that we know will guarantee us a solution.
        
        // Once we add a '(' we will then discard it and try a ')' which can only close a valid '('. 
        // Each of these steps are recursively called.
        
        if(noOpenB < n)               generateHelper(temp + '(', res, n, noOpenB + 1, noCloseB);
        if(noCloseB < noOpenB)        generateHelper(temp + ')', res, n, noOpenB, noCloseB + 1);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        
        string temp = "";
        int noOpenB = 0, noCloseB = 0;
        
        generateHelper(temp, res, n, noOpenB, noCloseB);
        
        return res;
    }
    
};