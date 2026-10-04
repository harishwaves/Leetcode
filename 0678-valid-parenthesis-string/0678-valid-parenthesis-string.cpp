class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        if(s[0]==')') return 0;
        if(s[n-1]=='(') return 0;
        stack<int> star,open;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return 0;
            }
        }
        while(!star.empty() && !open.empty()){
            if(open.top()>star.top()) return 0;
            star.pop();
            open.pop();
        }
        return open.empty();
    }
};