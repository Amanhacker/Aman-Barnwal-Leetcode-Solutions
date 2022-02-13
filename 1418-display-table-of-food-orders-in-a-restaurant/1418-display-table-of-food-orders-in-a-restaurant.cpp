class Solution {
public:
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        vector<vector<string>> res;
        int n = orders.size();
    
        map<pair<int, string>, int> mp;      // 1st arg - tableNo, 2nd arg - Food Item, 3rd arg - Food item occurence at that tableNo
        
        set<string> foods;                          // Contains all food items
        set<int> tables;                            // Contains tableNo

        pair<int, string> v1;               // 1st arg - tableNo, 2nd arg - Food Item
 
        for(auto &x : orders) {

            int i = 0;
            
            int tableNo = stoi(x[1]);
            string f = x[2];

            tables.insert(tableNo);
            foods.insert(f);
            
            v1 = {tableNo, f};
            mp[v1]++;
        }
        
        // For 1st row of res
        vector<string> temp;
        temp.push_back("Table");
        
        for(auto &x : foods)                                            temp.push_back(x);
        
        res.push_back(temp);
        temp.clear();
        
        // Fill the remaining tables

        for(auto &x : tables) {
            
            temp.push_back(to_string(x));
            
            // Fill the occurence data
            pair<int, string> t2;                // 1st arg - tableNo, 2nd arg - Food Item
            
            for(auto &x1 : foods) {
                t2 = make_pair(x, x1);
                temp.push_back(to_string(mp[t2]));
            }
            
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
    
};