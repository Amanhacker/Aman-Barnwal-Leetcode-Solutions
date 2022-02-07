class Solution {
public:
    
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
    
        vector<vector<int>> res;
        vector<int> path;
        
        int n = text.size();
        
        for(auto &x : words) {
            
            string temp = x;
            int stRange = 0;

            int n1 = temp.size();
         
            // Find the starting index and ending index of word "temp" in text
            
            while(stRange + n1 - 1 < n) {
                
                int stIndex = text.substr(stRange, n - stRange).find(temp);
                
                if(stIndex == string :: npos)                                       break;
                
                // Here, stIndex = stRange + stIndex, since substr got updated here in range search
                stIndex = stRange + stIndex;
                
                path.push_back(stIndex);
                path.push_back(stIndex + n1 - 1);

                res.push_back(path);
                path.clear();

                stRange = stIndex + 1;
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
};