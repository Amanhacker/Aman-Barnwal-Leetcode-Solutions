class Solution {
public:
   
    int minTimeToType(string word) {
    
        int ans = 0;
        int n = word.length();
        
        ans += n;
        
        // Initially, the pointer is pointed to char 'a'
        // Moving the pointer takes 1 sec and typing the character takes 1 sec each
        
        char temp = 'a';
        
        for(int i=0; i<n; i++) {
            
            char ch = word[i];
            
            // We need to go to ch from temp either clockwise or anticlockwise
            
            int t1 = abs((int)(ch) - (int)(temp));
            int t2 = abs(26 - t1);
            
            ans += min(t1, t2);
            temp = ch;
        }
        
        return ans;
    }
    
};