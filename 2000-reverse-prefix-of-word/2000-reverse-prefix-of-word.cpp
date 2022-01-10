class Solution {
public:
    
    string reversePrefix(string word, char ch) {
        
        string res;
        
        // Substring is from index 0 to first occurence of ch in string word
        int start = 0, end;
        int n = word.length();
        
        if(word.find(ch) == string::npos)                                   return word;
        else {
            
            // ch found in string word
            end = word.find(ch);
            
            string temp = word.substr(start, end - start + 1);
            reverse(temp.begin(), temp.end());
            
            if(end + 1 < n)                         res += temp + word.substr(end + 1, n - 1 - (end + 1) + 1);
            else                                    res += temp;
        }
        
        return res;
    }
    
};