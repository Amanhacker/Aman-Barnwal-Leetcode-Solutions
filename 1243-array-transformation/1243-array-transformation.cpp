class Solution {
public:
  
    vector<int> transformArray(vector<int>& a) {
    
        vector<int> temp;
        int n = a.size();
        
        for(int k=1; k<=n-2; k++) {
            
            temp = a;
            
            for(int i=1; i<=n-2; i++) {
                if(temp[i-1] > temp[i] && temp[i] < temp[i+1])                          a[i]++;
                else if(temp[i-1] < temp[i] && temp[i] > temp[i+1])                     a[i]--;
             }
            
            temp = a;
        }
        
        return temp;
    }
    
};