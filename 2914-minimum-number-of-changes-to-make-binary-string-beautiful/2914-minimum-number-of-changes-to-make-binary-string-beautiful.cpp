class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int i=0;
        int count = 0;
        while(i<n-1){
            if(s[i]!=s[i+1]) count++;
            i += 2;
        }
        return count;
    }
};