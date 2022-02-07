class Solution {
public:
    
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    
        int res = INT_MAX;
        vector<int> v1, v2;
        
        for(int i=0; i<wordsDict.size(); i++) {
            
            string temp = wordsDict[i];
            
            if(temp == word1)                               v1.push_back(i);
            else if(temp == word2)                          v2.push_back(i);
        }
    
        for(auto &x1 : v1) {
            for(auto &x2 : v2 )                             res = min(res, abs(x2 - x1));
        }
        
        return res;
    }
    
};