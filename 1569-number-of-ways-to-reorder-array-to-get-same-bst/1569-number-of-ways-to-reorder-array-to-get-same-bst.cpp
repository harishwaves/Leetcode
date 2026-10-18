class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long fact[1001];
    void precompute(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;
    }

    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        long long denominator =
            fact[r] * fact[n - r] % MOD;
        return fact[n] * power(denominator, MOD - 2) % MOD;
    }

    long long ways(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 1;
        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        int L = left.size();
        int R = right.size();
        long long result = nCr(L + R, L);
        result = result * ways(left) % MOD;
        result = result * ways(right) % MOD;
        return result;
    }

    int numOfWays(vector<int>& nums) {
        precompute(nums.size());
        return (ways(nums) - 1 + MOD) % MOD;
    }
};