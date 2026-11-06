class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const vector<int> a,const vector<int> b){
            return a[1] < b[1];
        });
        int m = logs.size();
        int q = queries.size();
        vector<pair<int,int>> timeidx(q);
        for(int i=0;i<q;i++) timeidx[i] = {queries[i],i};
        sort(timeidx.begin(),timeidx.end());
        
        unordered_map<int,int> mp;
        vector<int> ans(q);

        int i=0,j=0;
        for(auto ele : timeidx){
            int st = ele.first - x;
            int end = ele.first;
            int idx = ele.second;

            while(j<m && logs[j][1]<=end){
                mp[logs[j][0]] ++;
                j++;
            }
            while(i<m && logs[i][1]<st){
                mp[logs[i][0]] --;
                if(mp[logs[i][0]]==0) mp.erase(logs[i][0]);
                i++;
            }
            ans[idx] = n - mp.size();
        }
        return ans;
    }
};