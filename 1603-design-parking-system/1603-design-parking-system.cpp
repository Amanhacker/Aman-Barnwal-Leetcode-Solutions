class ParkingSystem {
public:
    
    vector<int> v;
    
    ParkingSystem(int big, int medium, int small) {
    
        v.resize(4);
        
        v[1] = big;
        v[2] = medium;
        v[3] = small;
    }
    
    bool addCar(int carType) {
             
        if(v[carType] >= 1) {
            v[carType]--;
            return true;
         }
         
        else                                          return false;
    }
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */