class Solution {
public:
    
    // Possible movements are up, right, down, left
    // (-1, 0), (0, 1), (1, 0), (0, -1)
//     int dx[4] = {-1, 0, 1,  0};
//     int dy[4] = { 0, 1, 0, -1};

//     string s[4] = {"U", "R", "D", "L"};
    
//     bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        
//         if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && grid[x][y] == 1)             return true;
//         else                                                                                    return false;
//     }
    
//     void bfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid, set<string> &w) {
        
//         queue<pair<int, int>> q;
//         q.push({x, y});
        
//         vis[x][y] = 1;
        
//         string str = "";
        
//         while(q.empty() == false) {
            
//             pair<int, int> temp = q.front();
//             q.pop();

//             for(int i=0; i<4; i++) {
                
//                 int x1 = temp.first + dx[i];
//                 int y1 = temp.second + dy[i];
                
//                 if(isValid(x1, y1, n, m, vis, grid) == true) {
                    
//                     str += s[i];
                    
//                     q.push({x1, y1});
//                     vis[x1][y1] = 1;
//                 }
//             }
//         }

//         cout << str << " ";
//         w.insert(str);
//         return;
//     }
    
    int n, m;
    set<string> ss;
    
    void dfs(vector<vector<int>> &a,int i,int j,string& s,string temp){
        if(i<0||i>=n||j<0||j>=m) 
            return;
        if(a[i][j]==0) 
            return;
        a[i][j]=0;          // visted so changing 1 to 0 to avoid reconsideration of this 1 again
        s+=temp;
        dfs(a,i-1,j,s,"U");     // U upar
        dfs(a,i+1,j,s,"N");     // N neeche
        dfs(a,i,j-1,s,"B");     // B bayein/left
        dfs(a,i,j+1,s,"D");     // D dayein/right
        s+="K";                 // khatm pattern
    }

    
    int numDistinctIslands(vector<vector<int>>& a) {
    
        int res = 0;
        
        n = a.size();
        m = a[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]!=0){
                    string s="";
                    dfs(a,i,j,s,"S");   // S shuru pattern 
                    ss.insert(s);
                }
            }
        }
        cout<<ss.size();
        
        res = ss.size();
        return res;
    }
    
};