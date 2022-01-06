class Solution {
public:
    int maxSubArray(vector<int>& a) {
        
        int n = a.size();
        
        int o_sum = a[0];
        int cur_sum = a[0];

        for(int i=1; i<n; i++) {

            if(cur_sum > 0)                     cur_sum += a[i];
            else                                cur_sum = a[i];

            if(o_sum < cur_sum)                 o_sum = cur_sum;
        }

        return o_sum;
    }
    
};