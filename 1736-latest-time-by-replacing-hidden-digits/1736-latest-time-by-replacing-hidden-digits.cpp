class Solution {
public:
    
    char findRequired(int ind, string time) {
        
        if(ind == 0) {
            if(time[1] == '?' || time[1] <= '3')          return '2';
            else                        return '1';
        }   
        
        else if(ind == 1) {
           if(time[0] <= '1')           return '9';
            else                        return '3';
        }
        
        else if(ind == 3)               return '5';
        else if(ind == 4)               return '9';
        
        return '0';
    } 
    
    string maximumTime(string time) {
    
        // Time would be between 00:00 and 23:59
        
        // 1st digit - [0, 2],          i.e     i = 0
        
        // i.e  i = 1
        
        // 2nd digit - [0, 9], if 1st digit = [0, 1]
        // 2nd digit - [0, 3], if 1st digit = '2'
        
        // 3rd digit - [0, 5]           i.e     i = 3
        // 4th digit - [0, 9]           i.e     i = 4
        
        time[0] = time[0] != '?' ? time[0] : (time[1] == '?' || time[1] <= '3') ? '2' : '1';
        time[1] = time[1] != '?' ? time[1] : time[0] == '2' ? '3' : '9';
        time[3] = time[3] != '?' ? time[3] : '5';
        time[4] = time[4] != '?' ? time[4] : '9';
        
        return time;
        
//         for(int i=0; i<time.length(); i++) {
//             if(time[i] == '?')                      time[i] = findRequired(i, time);
//         }
        
//         return time;
    }
    
};