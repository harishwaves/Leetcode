class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = 0,right=0;
            int idx=0;
            while(idx<i){
                if(s[idx]=='(') left++;
                if(s[idx]==')') right++;
                idx++;
            }
            ans = max(ans,abs(right-left));
        }
        return ans;
    }
};