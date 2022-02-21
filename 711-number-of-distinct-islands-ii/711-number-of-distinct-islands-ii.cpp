class Solution {
public:

   map<int, vector<pair<int, int>>> mp;
   int n, m;
    
   void dfs(int i, int j, vector<vector<int>> &a, int index) {

      // Base Condition
      if(i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)                return;

      a[i][j] = 0;
      mp[index].push_back({i, j});

      dfs(i + 1, j, a, index);
      dfs(i - 1, j, a, index);
      dfs(i, j -1, a, index);
      dfs(i, j + 1, a, index);

      return;
    }

    int numDistinctIslands2(vector<vector<int>>& a) {

        n = a.size();
        m = a[0].size();

        set<vector<pair<int, int>>> islandsCoordinates;
        int count = 1;

        for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++) {

                if(a[i][j] == 1) {
               
                   count++;
                    
                   dfs(i, j, a, count);

                   // Rotate for 90, 180, 270 rotations, and also 0 degree for translation

                   vector<vector<pair<int, int>>> rotations(8);

                   for(int k=0; k<mp[count].size(); k++) {

                      int x = mp[count][k].first;
                      int y = mp[count][k].second;

                      rotations[0].push_back({x, y});
                      rotations[1].push_back({x, -y});
                      rotations[2].push_back({-x, y});
                      rotations[3].push_back({-x, -y});
                      rotations[4].push_back({y, x});
                      rotations[5].push_back({y, -x});
                      rotations[6].push_back({-y, x});
                      rotations[7].push_back({-y, -x});
                   }

                    
                   for(int i=0; i<rotations.size(); i++) {
                        sort(rotations[i].begin(), rotations[i].end());
                   }

                   for(int i=0; i<rotations.size(); i++) {
                        for(int j=1; j<mp[count].size(); j++) {

                          // Applying roration of Conic section formula for all possible pairs of (x, y)

                          rotations[i][j].first = rotations[i][j].first - rotations[i][0].first;
                          rotations[i][j].second = rotations[i][j].second - rotations[i][0].second;

                        }

                        rotations[i][0].first = 0;
                        rotations[i][0].second = 0;
                   }

                   sort(rotations.begin(), rotations.end());
                   islandsCoordinates.insert(rotations[0]);
                }
           }
        }

        count = islandsCoordinates.size();
        return count;
    }
    
    
};