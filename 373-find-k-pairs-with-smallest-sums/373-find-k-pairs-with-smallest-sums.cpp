class Solution {
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    
        vector<vector<int>> res;
        
        if(nums1.size() == 0 || nums2.size() == 0)              return res;
        
        using pi = pair<int, vector<int>>;                      // 1st arg - sum, 2nd arg - vector of index pairs
        priority_queue<pi, vector<pi>, greater<pi>> pq;         // Min Heap
        
        for(int i=0; i<nums1.size(); i++)                      pq.push({nums1[i] + nums2[0], vector<int>({i, 0})});
        
        while(res.size() < k && pq.empty() == false) {
                
            pi temp = pq.top();
            pq.pop();

            int i = temp.second[0];
            int j = temp.second[1];

            res.push_back(vector<int>({nums1[i],nums2[j]}));

            if(j + 1 < nums2.size())                            pq.push({nums1[i] + nums2[j + 1], vector<int>({i, j + 1})});
        }
        
        return res;
    }
    
};