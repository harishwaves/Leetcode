class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        int openbracket = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') openbracket++;
            else if(s[i]==')') openbracket--;
            ans = max(ans,openbracket);
        }
        return ans;
    }
};