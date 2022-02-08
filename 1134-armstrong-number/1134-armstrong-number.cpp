class Solution {
public:
   
    bool isArmstrong(int n) {
    
        int k = 0;
        
        int num = n;
        vector<int> v;
        
        while(num > 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        
        k = v.size();
        
        int sum = 0;
        
        for(auto &x : v) {
            sum += pow(x, k);
        }
        
        return (sum == n);
    }
    
};