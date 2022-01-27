class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
    
       double res;
        vector<int> v;
        
        // Merge two sorted vectors a1 and a2 into a sorted vector v
        
        int n1 = a1.size();
        int n2 = a2.size();
        
        int i = 0, j = 0;
        
        while(i < n1 && j < n2) {
            
            if(a1[i] <= a2[j]) {
                v.push_back(a1[i]);
                i++;
            }
            else if(a1[i] > a2[j]) {
                v.push_back(a2[j]);
                j++;
            }
        }
        
        while(i < n1) {
            v.push_back(a1[i]);
            i++;
        }
        
        while(j < n2) {
            v.push_back(a2[j]);
            j++;
        }
        
        int siz = n1 + n2;
        
        // Now, if siz is odd, then Median is middle element
        // Else, median is average of two middle elements
        
        if(siz % 2 == 1)                                        res = v[siz/2];
        
        else {
            
            double val1 = v[(siz-1)/2];
            double val2 = v[siz/2];
            
            res = (val1 + val2) / 2;
        }
        
        return res;
    }
    
};