class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2) {
        int n = nums1.size();
        long long ans = 0;
        vector<int> diff(1e5+1,0);
        for (int i = 0; i < n; i++) {
            long long d = abs((long long)nums1[i] - nums2[i]);
            diff[d]++;
        }
        int op = (long long)k1 + k2;
        for(int i=1e5;i>0 && op>0;i--){
            int countop = min(op,diff[i]);
            diff[i-1] += countop;
            diff[i] -= countop;
            op -= countop;
        }
        for(long long i=1;i<1e5+1;i++){
            ans += diff[i]*i*i;
        }
        return ans;
    }
};