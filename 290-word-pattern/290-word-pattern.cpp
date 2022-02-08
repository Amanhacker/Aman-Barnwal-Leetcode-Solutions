class Solution {
public:
    
    bool wordPattern(string pat, string s) {
    
        vector<string> v;
        
        // Breaking input into word using string stream    
        
        stringstream ss(s);                                          // Used for breaking words
        string word;                                                 // To store individual words
        
        while(ss >> word) {
            v.push_back(word);
        }
    
        map<int, int> u;
        vector<int> r1, r2;
        
        int c = 0;
        
        for(int i=0; i<pat.length(); i++) {

            if(u[pat[i]] == 0) {
                
                u[pat[i]]++;
                
                c++;
                u[pat[i]] = c;
            }   
            
            r1.push_back(u[pat[i]]);
        }
        
        map<string, int> u2;
        c = 0;
        
        for(int i=0; i<v.size(); i++) {
           
            if(u2[v[i]] == 0) {
                
                u2[v[i]]++;
                
                c++;
                u2[v[i]] = c;
            }   
            
            r2.push_back(u2[v[i]]);
        }
        
        return (r1 == r2);
    }
    
};