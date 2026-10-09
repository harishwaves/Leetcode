class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else{
                if(open==0){
                    if(i<n-1 && s[i+1]==')') i++;
                    else ans++;
                    ans++;
                }
                else{
                    if(i<n-1 && s[i+1]==')') i++;
                    else ans++;
                    open--;
                }
            }
        }
        return ans + 2*abs(open);   
    }
};