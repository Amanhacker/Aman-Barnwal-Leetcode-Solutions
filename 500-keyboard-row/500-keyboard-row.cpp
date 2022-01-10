class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
    
        vector<string> res;
        int n = words.size();
        
        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";
        
        unordered_map<char, int> u;
        set<int> w;
        
        for(auto &x : first)                            u[x] = 1;               // Belongs to 1st row
        for(auto &x : second)                           u[x] = 2;               // Belongs to 2nd row
        for(auto &x : third)                            u[x] = 3;               // Belongs to 3rd row
        
        for(auto &x : words) {
            
            // Find the word which can be form by only one row
            for(auto &x1 : x)                           w.insert(u[tolower(x1)]);
            
            if(w.size() == 1)                           res.push_back(x);
            w.clear();
        }
        
        return res;
    }
    
};