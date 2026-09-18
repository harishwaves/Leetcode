class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26,-1);
        vector<int> end(26,0);
        vector<bool> isvalid(26,1);
        vector<string> result;
        for(int i=0;i<n;i++){
            if(start[s[i]-'a']==-1){
                start[s[i]-'a'] = i;
            }
            end[s[i]-'a'] = i;
        }
        for(int c=0;c<26;c++){
            if(start[c]==-1) continue;
            for(int i=start[c];i<end[c];i++){
                if(start[s[i]-'a']<start[c]){
                    isvalid[c] = 0;
                    break;
                }
                end[c] = max(end[c],end[s[i]-'a']);
            }
        }
        int lst_tkn_st = INT_MAX;
        for(int i=n-1;i>=0;i--){
            int c = s[i]-'a';
            if(!isvalid[c]) continue;
            if(i==start[c] && end[c]<lst_tkn_st){
                result.push_back(s.substr(i,end[c]-i+1)); 
                lst_tkn_st = i;
            }
        }
        return result;
    }
};