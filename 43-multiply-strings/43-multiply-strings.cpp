class Solution {
public:
    
    string multiply(string num1, string num2) {
    
        vector<int> res;
        
        if(num1 == "0" || num2 == "0")                                  return "0";
        
        int n = num1.size();
        int m = num2.size();
        
        res.resize(n + m, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] = res[i + j + 1] % 10;
            }
        }
        
        int i = 0;
        
        while(res[i] == 0) {
            i++;
        }
        
        string ans = "";
        
        while(i < res.size()) {
            ans += to_string(res[i]);
            i++;
        }
        
        return ans;
    }
    
};