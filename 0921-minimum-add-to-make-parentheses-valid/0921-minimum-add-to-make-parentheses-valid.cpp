class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int cnt = 0,open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
                cnt++;
            }
            else{
                if(open>0){
                    open--;
                    cnt--;
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt;
    }
};