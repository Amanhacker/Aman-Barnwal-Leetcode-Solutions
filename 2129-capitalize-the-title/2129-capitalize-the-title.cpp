class Solution {
public:
    
    string capitalizeTitle(string s) {
    
        string res;
        
        // If word length <= 2, then change all letters to lowercase, else change 1st letter to uppercase and remaining to lowercase
        int n = s.length();
        
        for(int i=0; i<n; i++) {
            
            int k = i;
            
            while(k < n && s[k] != ' ') {
                k++;
            }
            
            // Substring is from index i to (k - 1) i.e [i, k-1]
            string temp = s.substr(i, k-1-i+1);
            
            if(temp.size() <= 2) {
                for(auto &x : temp)                 x = tolower(x);
            }
            
            else{
                temp[0] = toupper(temp[0]);
                for(int i=1; i<temp.size(); i++)    temp[i] = tolower(temp[i]);
            }
            
            res += temp;
            
            i = k;
            if(i != n)                              res += ' ';
        }
        
        return res;
    }
    
};