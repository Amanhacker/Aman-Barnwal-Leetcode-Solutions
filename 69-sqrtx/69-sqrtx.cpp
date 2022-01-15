class Solution {
public:
    
    int binarySearch(int num, int start, int end) {
        
        if(start > end)                                 return -1;
        
        long long int mid, res;
        
        while(start <= end) {
        
            mid = start + (end - start) / 2;
        
            if(mid * mid == num)                            return mid;
            else if(mid * mid > num)                        end = mid - 1;
            else if(mid * mid < num) {
                res = mid;
                start = mid + 1;
            }                       
        }
        
        return res;
    }
    
    int mySqrt(int x) {
    
        // Checks whether there exists an interger i such that i*i = x using Binary Search
        int start = 0, end = x;
        
        return binarySearch(x, start, end);
    }
    
};