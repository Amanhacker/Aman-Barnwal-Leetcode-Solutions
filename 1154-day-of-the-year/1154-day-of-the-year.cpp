class Solution {
public:
    
     bool isLeap(int y) {
        
        // A year is a leap year iff 
        //        1). year % 400 == 0
        //        2). year % 4 == 0 && year % 100 != 0
        
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
    
    int dayOfYear(string date) {
    
        int res = 0;
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        int m = (stoi)(date.substr(5, 2));
        int d = (stoi)(date.substr(8));
        int y = (stoi)(date.substr(0, 4));
        
        res += d;
        
        // In case of Feb, no.of days is 29 instead of 28
        if(m > 2 && isLeap(y) == true)                          res++;
        
        for(int i=0; i<=m-2; i++)                               res += days[i];
        
        return res;
    }
    
};