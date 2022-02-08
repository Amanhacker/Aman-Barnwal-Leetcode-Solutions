class Solution {
public:
    
    // To find the power of a^m
    int findPower(int a, int m) {
        
        if(m == 0)                                      return 1;
        
        else if(m % 2 == 0)                             return findPower(a, m / 2) * findPower(a, m / 2);
        else if(m % 2 == 1)                             return a * findPower(a, m - 1);
        
        return -1;
    }
    
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
            sum += findPower(x, k);
        }
        
        return (sum == n);
    }
    
};