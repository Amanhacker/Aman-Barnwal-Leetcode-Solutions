class Solution {
public:

    string findString(int t) {
        
        if(t % 3 == 0 && t % 5 == 0)            return "FizzBuzz";
        else if(t % 3 == 0)                     return "Fizz";
        else if(t % 5 == 0)                     return "Buzz";
        else                                    return to_string(t);
    }
    
    vector<string> fizzBuzz(int n) {
    
        vector<string> res;
        
        for(int i=1; i<=n; i++) {
            res.push_back(findString(i));            
        }
        
        return res;
    }
    
};