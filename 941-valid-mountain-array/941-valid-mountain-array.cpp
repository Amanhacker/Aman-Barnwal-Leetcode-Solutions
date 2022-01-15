class Solution {
public:
    
    bool validMountainArray(vector<int>& a) {
    
        int n = a.size();
        
        int i = 0;
            
        while(i + 1 < n && a[i] < a[i + 1])           i++;

        // Peak can't be first or last
        if(i == 0 || i == n-1)                        return false;

        while(i + 1 < n && a[i] > a[i + 1])           i++;

        if(i == n-1)                                  return true;
        return false;
    }
    
};