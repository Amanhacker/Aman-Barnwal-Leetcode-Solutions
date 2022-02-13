class UndergroundSystem {
public:
    
    // Time taken = (checkout - checkin) / no of stations
    
    unordered_map<int, pair<string, int>> checkins;             // 1st arg -  id, 2nd arg - stationName, 3rd arg - time
    unordered_map<string, pair<int, int>> routes;      // 1st arg - (startStation, endStation), 2nd arg- frequency, 3rd arg - Time Difference
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
       
        checkins[id] = {stationName, t};
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        
        auto [station, start] = checkins[id];
        checkins.erase(id);
        
        string route = station + "," + stationName;
        
        routes[route].first++;
        routes[route].second += (t- start);
        
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double res = 0.0;
        
        auto &[noStations, sum] = routes[startStation + "," + endStation];
        
        if(noStations > 0)                                       res = (double)(sum) / noStations;
        return res;
    }
    
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */