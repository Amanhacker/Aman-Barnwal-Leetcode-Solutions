class Solution {
public:
    
    char nextGreatestLetter(vector<char>& letters, char target) {
    
        for(auto &x : letters) {
            if(x > target)                                      return x;
        }
        
        return letters[0];
    }
    
};