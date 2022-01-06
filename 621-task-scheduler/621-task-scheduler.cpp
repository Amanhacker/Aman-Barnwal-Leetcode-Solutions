class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> u;

        for(auto &x : tasks)					u[x]++;

        // For Max Heap
        priority_queue<int> pq;

        for(auto &x : u)						pq.push(x.second);

        int cycles = 0;

        while(pq.empty() == false) {

            vector<int> temp;

            for(int i=0; i<=n; i++) {
                
                if(pq.empty() == false) {
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for(auto &x : temp) {
                
                x--;

                if(x > 0)                           pq.push(x);
            }

            if(pq.empty() == true)					cycles += temp.size();
            else 									cycles += n + 1;
        }

        return cycles;
    }
};