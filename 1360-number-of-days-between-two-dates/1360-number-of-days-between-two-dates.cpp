class Solution {
public:
    
    bool isLeap(int y) {
        
        // A year is a leap year iff 
        //        1). year % 400 == 0
        //        2). year % 4 == 0 && year % 100 != 0
        
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); 
    }
    
    int solve(string date) {
        
        int res = 0;
        
        int y = stoi(date.substr(0, 4));
        int m = (stoi)(date.substr(5, 2));
        int d = (stoi)(date.substr(8));
        
        res += d;
        
        // No.of days in every month
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        for(int i=1971; i<y; i++) {
            if(isLeap(i) == true)                   res += 366;
            else                                    res += 365;
        }
        
        if(m > 2 && isLeap(y))                      res++;
        
        for(int i=0; i<=m-2; i++)                   res += days[i];
        return res;
    }
    
    int daysBetweenDates(string date1, string date2) {
    
        // Calculate the no.of days from 1900-01-01 to date
        
        int d1 = solve(date1);
        int d2 = solve(date2);
        
        return abs(d1 - d2);
    }
    
};