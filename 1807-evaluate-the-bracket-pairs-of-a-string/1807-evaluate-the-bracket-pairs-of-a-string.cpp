class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        int i=0;
        while(i<n){
            if(i<n-1 && s[i]=='('){
                i++;
                string key = "";
                while(i<n && s[i]!=')'){
                    key += s[i++];
                }
                if(i<n && s[i]==')') i++;
                if(mp.find(key)!=mp.end()){
                    ans += mp[key];
                }
                else ans += '?';
            }
            if(i<s.length() && s[i]!='(' && s[i]!=')') ans += s[i++];
        }
        return ans;
    }
};