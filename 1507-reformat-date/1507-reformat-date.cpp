class Solution {
public:
    
    string reformatDate(string date) {
    
        string res = "";
        
        int n = date.length();
        string year = "", mon = "", d = "";
        
        string month;
        string allMonths[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        if(n == 13) {
            
            // Date is of double digit
            // Date - [0,1] Month - [5, 7], year = [9, 12]
            
            year += date.substr(9, 4);
            d += date.substr(0, 2);
            
            month += date.substr(5, 3);
        }
        
        else if(n == 12) {
          
            // Date is of single digit
            // Date - [0] Month - [4, 6], year = [8, 11]
           
            year += date.substr(8, 4);
           
            d += '0';
            d += date[0];
            
            month += date.substr(4, 3);
        }
        
        for(int i=0; i<12; i++) {
           
             if(allMonths[i] == month) {
                
                if(i + 1 <= 9)                          mon += "0" + to_string(i + 1);
                else                                    mon = to_string(i + 1);
                
                break;
            }
        }
        
        res += year + "-" + mon + "-" + d;
        return res;
    }
    
};