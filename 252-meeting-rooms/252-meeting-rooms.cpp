class Solution {
public:
    
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if(a[0] == b[0])                                return a[1] < b[1];
        else                                            return a[0] < b[0];
    }
    
    bool canAttendMeetings(vector<vector<int>>& v) {
    
        int n = v.size();
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=1; i<n; i++) {
            
            if(v[i-1][1] > v[i][0])                     return false;
        }
        
        return true;        
    }
    
};