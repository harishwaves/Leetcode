class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        int prev = 0;
        string ans = "";
        for(int curr = 0;curr<n;curr++){
            count += s[curr]=='(' ? +1 : -1;
            if(count==0){
                ans.append(s.begin()+prev+1,s.begin()+curr);
                prev = curr+1;
            }
        }
        return ans;
    }
};