class Solution {
public:
    
    int countSegments(string s) {
    
        int count = 0;
        
        // Breaking input into word using string stream
        
        stringstream ss(s);                        // Used for breaking words
        string word;                               // to store individual words
        
        while(ss >> word)                           count++;
        
        return count;
    }
    
};