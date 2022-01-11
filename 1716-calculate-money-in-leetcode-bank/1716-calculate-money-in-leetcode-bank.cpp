class Solution {
public:
    
    int totalMoney(int n) {
    
        int ans = 0;
        vector<int> a(n + 1);
        
        a[1] = 1;
        
        for(int i=2; i<=n; i++) {
            
            if(i >= 8 && i % 7 == 1)                a[i] = a[i - 7] + 1;
            else                                    a[i] = a[i-1] + 1;
        }
        
        for(auto &x : a)                            ans += x;
        
        return ans;
    }
    
};