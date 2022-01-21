class Solution {
public:
    
    // Find all happy strings of length n in lexicgraphical order
    
    void findAllStrings(int n,int k, string temp, vector<string> &ans) {
        
        if(ans.size() == k)                                     return;
        
        // Base Condition
        if(temp.size() == n) {
            
            ans.push_back(temp);
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            
            if(temp.length() == 0 || temp[temp.size() - 1] != ch) {
                
                temp += ch;
                findAllStrings(n, k, temp, ans);
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
        findAllStrings(n, k, temp, ans);
       
        if(k > ans.size())                              return res;
        
        return ans[k-1];
    }
    
};