class SeatManager {
public:
    
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SeatManager(int n) {
        
        // Initially, all seats are unreserved, i.e all seats are in pq
        for(int i=1; i<=n; i++)                         pq.push(i);
    }
    
    int reserve() {
        
        int ans;
        
        if(pq.size() >= 1) {
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
    }
    
    void unreserve(int seatNumber) {
        
        pq.push(seatNumber);
        return;
    }
    
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */