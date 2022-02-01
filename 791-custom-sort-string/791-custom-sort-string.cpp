class Solution {
public:
    
    string customSortString(string order, string s) {
    
        string res = "";
        
        unordered_map<char, int> u;

        for(auto &x : order)                                           u[x]++;
        
        string last = "";
        string temp = "";
        
        for(auto &x : s) {

            if(u[x] == 0)                                              last += x;

            // if char x present in order
            if(u[x] >= 1)                                              temp += x;
        }
        
        // Sort temp according to the order of characters in string order
        string t = "";
        
        for(auto &x : order) {
            
            // if x present in temp string
            auto ind = temp.find(x);
            
            if(ind != string :: npos) {
                
                int freq = count(temp.begin(), temp.end(), x);
                while(freq--)                                           t += x;
            }
        }
        
        res += t + last;
        
        return res;
    }
    
};