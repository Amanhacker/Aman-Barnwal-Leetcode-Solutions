class MRUQueue {
public:
    
    vector<int> v;
    
    MRUQueue(int n) {
    
        for(int i=1; i<=n; i++)                         v.push_back(i);    
    }
    
    int fetch(int k) {
    
        // Removes the kth element and moves it to the end (Considering 1-based indexing)        
        
        int temp = v[k-1];
        v.erase(v.begin() + k - 1);
        
        v.push_back(temp);
        return temp;
    }
    
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */