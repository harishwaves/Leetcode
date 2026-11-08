class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bool communicate = 0;
                    for(int col=0;col<n;col++){
                        if(col!=j && grid[i][col]==1){
                            communicate = 1;
                            break;
                        }
                    }
                    if(communicate) count++;
                    else{
                        for(int row=0;row<m;row++){
                            if(row!=i && grid[row][j]==1){
                                communicate = 1;
                                break;
                            }
                        }
                        if(communicate) count++;
                    }
                }
            }
        }
        return count;
    }
};