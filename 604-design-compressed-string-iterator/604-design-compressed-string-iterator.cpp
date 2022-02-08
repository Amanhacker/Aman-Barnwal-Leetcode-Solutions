class StringIterator {
public:
    
    int n;
    string res;
    
    int ptr = 0, num = 0;
    char ch = ' ';
    
    StringIterator(string s) {

        n = s.length();
        res = s;
    }
    
    
    char next() {
        
        if(hasNext() == false)                                          return ' ';
        
        else if(num == 0) {
            
            ch = res[ptr];
            ptr++;
            
            while(ptr < n && isdigit(res[ptr])) {
                num = (10 * num) + (res[ptr] - '0');
                ptr++;
            }
        }   

        num--;
        return ch;
    }
    
    bool hasNext() {
    
       return ( ptr != res.length() || num != 0 );
    }
    
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */