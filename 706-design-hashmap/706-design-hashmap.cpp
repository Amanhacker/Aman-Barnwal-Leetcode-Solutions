class MyHashMap {
public:
    
    
    int u[1000001];
    
    MyHashMap() {
        fill(u, u + 1000001, -1);    
    }
    
    void put(int key, int value) {
        u[key] = value;
        return;
    }
    
    int get(int key) {
        return u[key];
    }
    
    void remove(int key) {
        u[key] = -1;
        return;
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */