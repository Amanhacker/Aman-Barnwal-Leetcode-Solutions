class Solution {
public:
    
    int badSensor(vector<int>& a1, vector<int>& a2) {
    
        int res = -1;
        
        int n = a1.size();
        int i = 0;
        
        // Increment index i until we find first missmatch.
        while(i < n && a1[i] == a2[i])                                          i++;

        // From there, keep going if characters alternate s1[i] == s2[i + 1] && s1[i + 1] == s2[i]
        while(i + 1 < n && a1[i] == a2[i + 1] && a1[i + 1] == a2[i])            i++;

        // If we reach the last character, sensor readings are ambigous - return -1.
        if(i >= n - 1)                                                          res = -1;
        
        // If s1[i] == s2[i + 1], the first sensor if faulty        
        else if(a1[i] == a2[i+1])                                               res = 1;    
        
        // Otherwise, the second sensor is faulty.
        else                                                                    res = 2;

        return res;
    }
    
};