class SparseVector {
public:
    
    int n;
    vector<pair<int, int>> v;
    
    SparseVector(vector<int> &nums) {
        
        n = nums.size();    
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0)                                                v.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
    
        int sum = 0;
        
        for(int i=0, j=0; i<v.size() && j<vec.v.size(); i++, j++) {
            
            if(v[i].first < vec.v[j].first)                                 j--;
            else if(v[i].first > vec.v[j].first)                            i--;
            else                                                            sum += (v[i].second) * (vec.v[j].second);
        }
        
        return sum;
    }
    
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);