class Solution {
public:
    
    int minOperations(vector<string>& logs) {
    
        int count = 0;
        int n = logs.size();
        
        for(auto &x : logs) {
            
            if(x[0] != '.')                                     count++;
            else if(x.size() == 3 && x[2] == '/') {
                if(count > 0)                                   count--;
            }
        }
        
        return count;
    }
    
};