class Solution {
public:
    
    int numDifferentIntegers(string word) {
    
        int count = 0;
        
        int n = word.length();
        set<string> w;
        
        for(int i=0; i<n; i++) {
            
            if(isdigit(word[i])) {
                
                int start = i, end;
                
                while(i >= 0 && isdigit(word[i]))               i++;
                
                if(i == start)                                  w.insert(to_string(word[start]));
                
                else {
                    
                    while(start < n && word[start] == '0')      start++;
                    
                    end = i - 1;                     
                    string temp = word.substr(start, end - start + 1);
                    
                    w.insert(temp);
                }   
            }
        }
        
        count = w.size();
        return count;
    }
    
};