class Solution {
public:
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
    
        string res = "";
        int len = INT_MAX;
            
        unordered_map<char, int> u, u1;
        
        for(auto &x : licensePlate) {
            if(isalpha(x)) {
                char c = tolower(x);
                u[c]++;
            }
        }
        
        for(auto &x : words) {
            
            string temp = x;
            u1 = u;
            
            for(auto &y : temp) {
                char c = tolower(y);
                u1[c]--;
            }
            
            bool flag = true;
            
            for(auto &y : u1) {
                if(y.second > 0)                           flag = false;
            }
            
            if(flag == true) {
                if(len > (int)temp.size()) {
                    len = temp.size();
                    res = temp;
                }
            }
            
            u1.clear();
        }
        
        return res;
    }
    
};