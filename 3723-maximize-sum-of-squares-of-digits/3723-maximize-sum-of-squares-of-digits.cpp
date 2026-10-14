class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(ans.length()<num){
            string curr = to_string(min(9,sum));
            ans += curr;
            sum -= stoi(curr);
        }
        if(sum>0) return "";
        return ans;
    }
};