class Solution {
public:
   
    int timeRequiredToBuy(vector<int>& v, int k) {
    
        int time = 0;
        int n = v.size();
        
        map<int, int> mp;
        
        while(v[k] > 0) {

            // Decrease each element of array by 1
            
            for(int i=0; i<n && v[k] > 0; i++) {
                
                if(v[i] == 0)                      mp[i] = 1;
                
                if(mp[i] == 0 && v[i] > 0) {
                    v[i]--;
                    time++;
                }
            }
            
            cout << time << endl;
            
            for(auto &x : v)                        cout << x << " ";
            cout << endl;
        }
        
        return time;
    }
    
};