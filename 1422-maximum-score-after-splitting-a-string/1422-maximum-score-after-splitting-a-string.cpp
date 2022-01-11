class Solution {
public:
    
    int maxScore(string s) {
    
        int res = 0;
        
        // Zeroes in left, and ones in right
        int n = s.length();
        
        vector<int> left(n), right(n);
        
        if(s[0] == '0')               left[0] = 1;
        else                          left[0] = 0;
        
        for(int i=1; i<n; i++) {
            
            if(s[i] == '0')           left[i] = left[i-1] + 1;
            else                      left[i] = left[i-1];
            
            cout << left[i] << " ";
        }
        
        if(s[n-1] == '1')             right[n-1] = 1;
        else                          right[n-1] = 0;
        
        cout << endl;
        
        for(int i=n-2; i>=0; i--) {
            
            if(s[i] == '1')           right[i] = right[i+1] + 1;
            else                      right[i] = right[i+1];
            
            cout << right[i] << " ";
        }
        
        cout << "AMan" << endl;
        
        for(int i=0; i<n-1; i++) {
            cout << left[i] << " " << right[i] << endl;
            res = max(res, left[i] + right[i+1]);
        }
        
        return res;
    }
    
};