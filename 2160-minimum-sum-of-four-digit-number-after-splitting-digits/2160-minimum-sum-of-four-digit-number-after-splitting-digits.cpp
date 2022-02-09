class Solution {
public:
    
    int minimumSum(int num) {
    
        int res = 0;
        
        // Split num into min two numbers
        
        vector<int> v;
        int n = num;
        
        while(n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        
        sort(v.begin(), v.end());
        
        int t = v[2] + v[3];
        int carry = 0;
        
        if(t <= 9)                               res += t;
        
        else {
            
            carry = t / 10;
            res = (t % 10);
        }   
        
        res = res + ( 10 * (carry + v[0] + v[1]) );
        return res;
    }
    
};