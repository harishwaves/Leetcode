class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n%2!=0) return false;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(st.size() &&( (st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']'))) st.pop();
            else st.push(s[i]);
        }
        if(st.size()==0) return true;
        return false;
    }
};