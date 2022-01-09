class Solution {
public:
    
    int eatenApples(vector<int>& apples, vector<int>& days) {
    
        int d = 1;
        int time = 0;

        // Form a Max Heap
        priority_queue<pair<int, int>> pq;		// 1st arg - rotten days, 2nd arg - No.of apples

        for(int i=0; i<apples.size(); i++) {

            pq.push({ -(d + days[i]), apples[i] });

            while(pq.empty() == false && -pq.top().first <= d)                      pq.pop();

            if(pq.size() >= 1) {

                pair<int, int> temp = pq.top();
                pq.pop();

                temp.second--;
                time++;

                if(temp.second >= 1)			                                    pq.push(temp);
            }

            d++;
        }

        while(pq.empty() == false) {

            while(pq.empty() == false && -pq.top().first <= d)                      pq.pop();

            if(pq.size() >= 1) {

                pair<int, int> temp = pq.top();
                pq.pop();

                temp.second--;
                time++;

                if(temp.second >= 1)			                                    pq.push(temp);
            }

            d++;
        }

        return time;
    }
    
};