class Solution {
public:
    
    int minCost(string a, vector<int>& neededTime) {
    
        int time = 0;
        int n = a.size();
        
        for(int i=0; i<n; ) {
            
            // Find whether the same colors are consecutive
            
            int sum = neededTime[i];
            int maxi = neededTime[i];
        
            bool flag = true;
            int j = i;
            
            while(j + 1 < n && a[j] == a[j + 1]) {
                
                sum += neededTime[j + 1];
                maxi = max(maxi, neededTime[j + 1]);
                
                flag = false;
                j++;
            }
            
            if(flag == false) {
                time += sum - maxi;
                i = j + 1;
            }
            
            else                    i++;
        }
        
        return time;
    }
    
};