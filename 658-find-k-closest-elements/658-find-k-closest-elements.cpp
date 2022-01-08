class Solution {
public:
    
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first)                          return a.second < b.second;
        else                                            return a.first < b.first;
    }
    
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
    
        // Return the k closest integers to x in ascending order
        vector<int> res;
        
        if(v.size() == 0)                                           return res;

        vector<int> temp;               // Stores k elements which is greater than x and also less than k

        // If x present in v
        int c = count(v.begin(), v.end(), x);
        while(c--)                                                  temp.push_back(x);
        
        // Form Max Heap and Min Heap
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        
        for(auto &x : v) {
            pq1.push(x);
            pq2.push(x);
        }
        
        
        // Max Heap
        
        while(pq1.empty() == false) {
            
            // Push all elements smaller than x into one vector
            if(pq1.top() < x) {
                
                while(pq1.empty() == false) {
                    temp.push_back(pq1.top());
                    cout << pq1.top() << " ";
                    pq1.pop();
                }
                
                break;
            }
            
            if(pq1.empty() == false)                                pq1.pop();
        }
        
        cout << endl;
        cout << "Aman" << endl;
        
        // Min Heap
        
        while(pq2.empty() == false) {
            
            // Push all elements larger than x into one vector
            if(pq2.top() > x) {
                
                while(pq2.empty() == false) {
                    temp.push_back(pq2.top());
                    cout << pq2.top() << " ";
                    pq2.pop();
                }
            }
            
            if(pq2.empty() == false)                                pq2.pop();
        }
        
        
        vector<pair<int, int>> vect;            // 1st arg - Diff of x and element, 2nd arg - element
        
        for(auto i : temp)                                          vect.push_back({abs(i - x), i});
        
        sort(vect.begin(), vect.end(), cmp);
        int count = 0;
        
        for(auto i : vect) {
            
            count++;
            res.push_back(i.second);
            
            if(count == k)                                          break;
        }
        
        sort(res.begin(), res.end());
        return res;
    }
    
};