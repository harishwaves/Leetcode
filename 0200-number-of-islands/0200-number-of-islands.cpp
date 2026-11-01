
class Solution {
public:
    int m, n;

    void bfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& visited) {

        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   grid[nrow][ncol] == '1' &&
                   !visited[nrow][ncol]) {

                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(grid, i, j, visited);
                }
            }
        }

        return ans;
    }
};
