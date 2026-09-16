const int mod = 1000000007;
class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n),prefixsum(n+1);
        for(int i=0;i<n;i++){
            dp[i] = 1;
            prefixsum[i+1] = (prefixsum[i]+dp[i])%mod;
        }
        for(int i=1;i<=k;i++){
            dp[0] = 0;
            for(int j=1;j<n;j++){
                dp[j] = (dp[j-1] + prefixsum[j])%mod;
            }
            for(int j=0;j<n;j++){
                prefixsum[j+1] = (prefixsum[j]+dp[j])%mod;
            }
        }
            return dp[n-1];
    }
};