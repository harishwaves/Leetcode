class Solution {
public:
    int m,n;
    int help(vector<vector<int>>& grid,int i,int j,int xo,vector<vector<vector<int>>>& dp){
        if(i>=m || j>=n) return INT_MAX;
        xo ^= grid[i][j];
        if(i==m-1 && j==n-1) return xo;
        if(dp[i][j][xo] != -1) return dp[i][j][xo];
        int rgt = help(grid,i,j+1,xo,dp);
        int dwn = help(grid,i+1,j,xo,dp);
        return dp[i][j][xo] = min(rgt,dwn);
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return help(grid,0,0,0,dp);
    }
};