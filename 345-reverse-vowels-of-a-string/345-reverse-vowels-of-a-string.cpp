class Solution {
public:
    
    bool isVowel(char ch) {
        
        ch = tolower(ch);
        
        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string reverseVowels(string s) {
    
        unordered_map<int, int> u;
        string res = "";
        
        for(int i=0; i<s.length(); i++) {
            
            if(isVowel(s[i]) == true) {
                u[i]++;                
                res += s[i];
            }   
        }
        
        int j = res.length() - 1;
        
        for(int i=0; i<s.length(); i++) {
            
            if(u[i] > 0) {
                
                s[i] = res[j];
                
                u[i]--;
                j--;
            }
        }
        
        return s;
    }
    
};