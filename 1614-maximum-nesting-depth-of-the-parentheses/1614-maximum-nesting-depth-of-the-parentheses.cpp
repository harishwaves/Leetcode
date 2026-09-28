class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push('(');
            else if(s[i]==')') st.pop();
            ans = max(ans,(int)st.size());
        }
        return ans;
    }
};