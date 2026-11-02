class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long median = 0;
        if(n%2==1) median = nums[n/2];
        else median = nums[n/2-1] + (nums[(n/2)] - nums[n/2-1])/2;
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(nums[i]-median);
        }
        return ans;
    }
};