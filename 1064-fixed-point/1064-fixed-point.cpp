class Solution {
public:
   
    int fixedPoint(vector<int>& a) {
    
        for(int i=0; i<a.size(); i++) {
            if(a[i] == i)                               return i;
        }
        
        return -1;
    }
    
};