class TwoSum {
public:
    
    vector<int> v;
    
    TwoSum() {
    
        
    }
    
    void add(int number) {
    
        v.push_back(number);
        return;
    }
    
    bool find(int value) {
        
        // Checks whether we are able to find two value whose sum is equal to value
        sort(v.begin(), v.end());
        
        int i = 0, j = v.size() - 1;
        
        while(i < j) {
            if(v[i] + v[j] == value)                                return true;
            else if(v[i] + v[j] > value)                            j--;
            else if(v[i] + v[j] < value)                            i++;                                        
        }
        
        return false;
    }
    
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */