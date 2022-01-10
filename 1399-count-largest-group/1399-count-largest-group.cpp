class Solution {
public:

    int sumDigits(int num) {
        
        int ans = 0;
        
        while(num > 0) {
            ans += num % 10;
            num = num / 10;
        }
        
        return ans;
    }
    
    int countLargestGroup(int n) {
    
        int count = 0;
        unordered_map<int, vector<int>> u;
        
        for(int i=1; i<=n; i++) {
            
            int sum = sumDigits(i);
            u[sum].push_back(i);
        }
        
        int maxSize = INT_MIN;
        
        for(auto &x : u)                                            maxSize = max(maxSize, (int)(x.second.size()));
        
        for(auto &x : u) {
            if(x.second.size() == maxSize)                          count++;
        }
        
        return count;
    }
    
};