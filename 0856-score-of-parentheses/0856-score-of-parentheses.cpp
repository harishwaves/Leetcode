class Solution {
public:
    int helper(string s,int start,int end){
        int open = 0,ans = 0;
        for(int i=start;i<end;i++){
            open += s[i]=='(' ? 1 : -1;
            if(open==0){
                if(i==start+1) ans += 1;
                else ans += 2*helper(s,start+1,i);
                start = i+1;
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        return helper(s,0,s.length());
    }
};