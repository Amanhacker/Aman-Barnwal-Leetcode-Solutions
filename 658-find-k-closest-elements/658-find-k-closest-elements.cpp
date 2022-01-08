class Solution {
public:
    
    int x1;
 
//     static bool cmp(const int &a, const int &b) {
        
//         if(abs(a - x1) == abs(b - x1))                      return a < b;
//         else                                                return abs(a - x1) < abs(b - x1);
//     }
    
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
    
        vector<int> res;
        
        x1 = x;
        
        // Sort the elements of v according to distance from x
        //sort(v.begin(), v.end(), cmp);
        
        stable_sort(v.begin(), v.end(), [x](const auto a, const auto b) {
            return abs(a - x) < abs(b - x);  
        });
         
        v.resize(k);
        sort(v.begin(), v.end());
        
        return v;
    }
    
};