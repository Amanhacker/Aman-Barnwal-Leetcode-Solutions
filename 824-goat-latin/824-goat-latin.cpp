class Solution {
public:
   
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
    
    string toGoatLatin(string s) {
    
        string res = "";
        vector<string> v;
        
        stringstream ss(s);
        string word;
        
        while(ss >> word) {
            v.push_back(word);
        }
        
        int n = v.size();
        int c = 1;
        
        for(int i=0; i<n; i++) {
            
            string temp = v[i];

            if(isVowel(temp[0]) == true) {
                // Add ma at end of word
                temp += "ma";
            }
            
            else {
                
                // Remove the first letter and append at end
                char ch = temp[0];
                
                temp.erase(temp.begin());
                
                temp += ch;
                temp += "ma";
            }
            
            // Add (c no.of a's) at the end of temp
            int k = c;
            
            while(k--)                              temp += "a";
            
            if(i < n-1)                             res += temp + " ";
            else                                    res += temp;
            
            c++;
        }
        
        return res;
    }
    
};