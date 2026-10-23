class Solution {
public:
    void dfs(int curr,vector<vector<int>>& adj,vector<bool>& visited){
        visited[curr] = 1;
        for(auto it: adj[curr]){
            if(!visited[it]) dfs(it,adj,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<bool> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                ans++;
            }
        }
        return ans;
    }
};