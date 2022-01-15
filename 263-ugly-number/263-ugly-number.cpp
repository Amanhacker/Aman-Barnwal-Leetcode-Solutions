class Solution {
public:
    
    void findPrimeDivisors(int n, vector<int> &res) {
        
        if(n % 2 == 0){
            res.push_back(2);
            while(n % 2 == 0)              n = n / 2;
        }

        if(n == 1)                         return;
        
        for(long long int i=3; i*i<=n; i += 2){

            if(n % i == 0){

                res.push_back(i);

                while(n % i == 0)           n = n / i;

            }
        }

        if(n == 1)                          return;
        
        if(n != 2)                          res.push_back(n);
        return;
    }
    
    bool isUgly(int n) {
    
        // Find all the prime factors of number
        vector<int> res;
        
        if(n <= 0)                                                      return false;
        if(n == 1)                                                      return true;
        
        findPrimeDivisors(n, res);
       
        if(res.size() <= 3) {
           
            for(auto &x : res) {
                cout << x << " ";
                if(x != 2 && x != 3 && x != 5)                          return false;  
            }
            
            return true;
        }
        
        return false;
    }
    
};