class Solution {
public:
    int countDaysTogether(string a, string b, string c, string d) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 0; i < 11; i++){
            days[i + 1] += days[i];
        }
        
        auto getDayNumber = [&](string s) {
            int month = (s[0] - '0') * 10 + (s[1] - '0');
            int day = (s[3] - '0') * 10 + (s[4] - '0');
            int prev_days = (month == 1) ? 0 : days[month - 2];
            return prev_days + day;
        };

        int sta = getDayNumber(a);
        int stb = getDayNumber(c);
        int ena = getDayNumber(b);
        int enb = getDayNumber(d);

        return max(0, min(ena, enb) - max(sta, stb) + 1);
    }
};