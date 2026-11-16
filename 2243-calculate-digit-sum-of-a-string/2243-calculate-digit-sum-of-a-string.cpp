class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            int n = s.length();
            string sumstr = "";
            for(int i=0;i<n;i+=k){
                string ss = s.substr(i,min(k,abs(n-i)));
                sumstr += to_string(accumulate(ss.begin(),ss.end(),0,[](int sum,char d){ return sum + d - '0';}));
            }
            s = sumstr;
        }
        return s;
    }
};