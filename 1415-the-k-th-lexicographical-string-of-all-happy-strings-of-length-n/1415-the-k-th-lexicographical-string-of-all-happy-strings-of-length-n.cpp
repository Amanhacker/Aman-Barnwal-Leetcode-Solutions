class Solution {
public:
    
    // Find all happy strings in lexicgraphical order
    
    void findAllStrings(int n, string temp, vector<string> &ans) {
        
        // Base Condition
        if(temp.size() == n) {
            
            ans.push_back(temp);
            temp = "";
            
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            
            if(temp.length() == 0 || temp[temp.size() - 1] != ch) {
                
                temp += ch;
                findAllStrings(n, temp, ans);
                temp.pop_back();
            }
        }
        
        return;
    }
    
    string getHappyString(int n, int k) {
    
        string res = "";
        vector<string> ans;
        
        // Recursively all the substrings of length n, and then return (k-1)th string
        
        string temp = "";
        findAllStrings(n, temp, ans);
       
        if(k > ans.size())                              return res;
        
        sort(ans.begin(), ans.end());
        res = ans[k-1];
        
        return res;
    }
    
};