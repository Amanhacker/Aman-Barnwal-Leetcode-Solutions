class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
    
        int n = digits.size();

        int carry = 1;
        
        for(int i=n-1; i>=0; i--) {
            
            int temp = digits[i] + carry;
            
            if(temp <= 9) {
                digits[i] = temp;
                carry = 0;
            }   
            else {
                digits[i] = (temp) % 10;
                carry = temp / 10;
            }
        }
        
        if(carry == 0)                              return digits;
        
        reverse(digits.begin(), digits.end());
        vector<int> res;
        
        while(carry > 0) {
            
            int t = carry % 10;
            carry = carry / 10;
            
            res.push_back(t);
        }
        
        int n1 = res.size();
        
        for(int i=n1-1; i>=0; i--) {
            digits.push_back(res[i]);
        }
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
    
};