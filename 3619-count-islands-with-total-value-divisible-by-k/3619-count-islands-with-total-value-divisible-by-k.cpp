class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& grid,int i,int j,long long& sum){
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        if(grid[i][j]==0) return;
        sum += grid[i][j];
        grid[i][j] = 0;
         dfs(grid,i+1,j,sum);
         dfs(grid,i-1,j,sum);
        dfs(grid,i,j+1,sum);
         dfs(grid,i,j-1,sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum = 0;
                    dfs(grid,i,j,sum);
                    if(sum%(long long)k==0) ans++;
                }
            }         
        }
        return ans;
    }
};