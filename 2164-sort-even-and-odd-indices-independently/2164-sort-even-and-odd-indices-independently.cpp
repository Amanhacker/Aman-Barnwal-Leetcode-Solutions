class Solution {
public:
    
    vector<int> sortEvenOdd(vector<int>& a) {
    
        vector<int> res;
        int n = a.size();
        
        vector<int> oddInd, evenInd;
        
        for(int i=0; i<n; i++) {
            if(i % 2 == 1)                                      oddInd.push_back(a[i]);
            else                                                evenInd.push_back(a[i]);
        }

        sort(evenInd.begin(), evenInd.end());
        sort(oddInd.begin(), oddInd.end(), greater<int>());        
        
        for(int i=0, j=0; i < evenInd.size() || j < oddInd.size(); i++, j++) {
            if(i < evenInd.size())                               res.push_back(evenInd[i]);
            if(j < oddInd.size())                                res.push_back(oddInd[j]);
        }        
        
        return res;
    }
    
};