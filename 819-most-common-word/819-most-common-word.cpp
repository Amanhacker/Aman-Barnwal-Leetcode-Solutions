class Solution {
public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
    
        string ans = "";
        int maxi = 0;
        
        unordered_map<string, int> u;
        string word = "";
        
        for(int i=0; i<paragraph.length(); ) {
            
            if(!isalpha(paragraph[i])) {
                
                while(!isalpha(paragraph[i]) && i < paragraph.length())               i++;
                
                u[word]++;
                word = "";
            }
           
            else {
                word += tolower(paragraph[i]);                
                i++;
            }   
        }   
        
        if(word != "")                  u[word]++;
        
        for(auto &x : u) {
            
            if(x.second > maxi && find(banned.begin(), banned.end(), x.first) == banned.end()) {
                
                ans = x.first;
                maxi = x.second;
            }
        }
    
        return ans;
    }
    
};