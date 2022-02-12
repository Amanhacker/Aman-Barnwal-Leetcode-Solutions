class Solution {
public:
    
    string findContestMatch(int n) {
    
        string res = "";
        
        // Pair according to rank in each scanario
        
        stack<string> st;
        map<int, string> mp;
        
        for(int i=1, j=n, k=1; i<j; i++, j--) {
            
            // Make the pair (i, j)
            string temp = "(" + to_string(i) + "," + to_string(j) + ")";
            
            mp[k] = temp;
            k++;
        }
        
        // First round of pair is already done
            
        while(true) {

            vector<string> v;
            for(auto &x : mp)                           v.push_back(x.second);

            if(v.size() == 1)                           break;

            map<int, string> u;
            int k = 1;

            for(int i=0, j=v.size()-1; i<j; i++, j--) {

                string temp = "(" + v[i] + "," + v[j] + ")";

                u[k] = temp;
                k++;
            }

            mp = u;
            v.clear();
        }
        
        res += mp[1];
        
        return res;
    }
    
};