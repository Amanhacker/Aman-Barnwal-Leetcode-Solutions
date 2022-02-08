class Logger {
public:
   
    map<string, int> u;
        
    Logger() {
    
    }
    
    bool shouldPrintMessage(int timestamp, string message) {

        if(u[message] == 0 || ( u[message] != 0 && timestamp >= u[message]) ) {
            u[message] = timestamp + 10;
            return true;
        }
        
        return false;
    }
    
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */