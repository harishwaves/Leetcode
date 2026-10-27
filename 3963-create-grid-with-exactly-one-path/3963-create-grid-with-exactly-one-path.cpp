class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++){
            string s = ".";
            for(int j=1;j<n;j++){
                if(i==m-1) s += '.';
                else  s += '#';     
            }
            ans.push_back(s);
        }
        return ans;
    }
};