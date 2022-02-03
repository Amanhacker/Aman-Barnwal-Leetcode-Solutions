class MovingAverage {
public:
    
    vector<int> v;
    int siz;
    
    MovingAverage(int size) {
    
        siz = size;    
    }
    
    double next(int val) {
    
        v.push_back(val);
        
        double res = 0.0;
        
        for(int i=v.size()-1, j=0; i>=0 && j<siz; i--, j++) {
            res += v[i];    
        }
        
        int sizReq = min(siz, (int)(v.size()));
        res = res / sizReq;
        
        return res;
    }
    
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */