class Solution {
public:
    
    // Here, we assume that a > b
    int gcd(int a, int b) {
        
        int rem;
        
        while(b > 0) {
            
            rem = a % b;
            
            a = b;
            b = rem;
        }

        return a;
    }
    
    int findGCD(vector<int>& v) {
    
        int n = v.size();
        sort(v.begin(), v.end());
        
        return gcd(v[0], v[n-1]);
    }
    
};