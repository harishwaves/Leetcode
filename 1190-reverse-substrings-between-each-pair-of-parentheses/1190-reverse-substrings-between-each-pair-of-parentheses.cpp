class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(ans.length());
            else if(s[i]==')'){
                int skip = st.top();
                st.pop();
                reverse(ans.begin()+skip,ans.end());
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};