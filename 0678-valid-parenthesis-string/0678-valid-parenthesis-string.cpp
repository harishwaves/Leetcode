class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if(s[0]==')') return 0;
        if(s[n-1]=='(') return 0;
        int star=0,open=0,close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*') open++;
            else open--;
            if(s[n-i-1]==')' || s[n-i-1]=='*') close++;
            else close--;
            if(open<0 || close<0) return 0;
        }
        return 1;
    }
};