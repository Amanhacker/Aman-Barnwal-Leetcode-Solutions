class Solution {
public:
    
    bool isPerfectSquare(int num) {
    
        int n = sqrt(num);
        return (n * n == num);
    }
    
};