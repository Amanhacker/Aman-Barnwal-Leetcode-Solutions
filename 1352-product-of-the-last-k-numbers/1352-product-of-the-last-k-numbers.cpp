class ProductOfNumbers {
public:
    
    // We maintain the runnig product in the Prefix array. To get the product for the last k elements, we divide the last running product by the product that was k - 1 steps ago.

    // v contains the running product in the Prefix array
    vector<int> v = {1};
    
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        
        if(num == 0)                    v = {1};
        else                            v.push_back(v.back() * num);
        
        return;
    }
    
    int getProduct(int k) {
        
        if(k >= v.size())               return 0;
        else                            return v.back() / v[v.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */