class Solution {
public:
    int helper(string s,int start,int end){
        int n = s.length();
        int openbracket = 0;
        int closebracket = 0;
        int mxlen=0; 
        for(int i=start;i<end;i++){
            if(s[i]=='(') openbracket++;
            else closebracket++;
            if(openbracket==closebracket){
                mxlen = max(mxlen,openbracket+closebracket);
            }
            if(closebracket>openbracket){
                openbracket = 0;
                closebracket = 0;
            }
        }
        return mxlen;
    }
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n==0) return 0;
        int mxlen = 0;
        int i=0;
        while (i < n && s[i] == ')') {
            i++;
        }
        while (n > i && s[n - 1] == '(') {
            n--;
        }
        if (i >= n) return 0;
        while(i<n){
            if(s[i]==')') i++;
            mxlen = max(mxlen,helper(s,i,n));
            i++;
        }
        return mxlen;
    }
};