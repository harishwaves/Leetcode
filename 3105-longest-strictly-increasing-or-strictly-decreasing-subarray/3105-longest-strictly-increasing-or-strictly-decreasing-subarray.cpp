class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mxinc = 1,mxdec = 1;
        int ans = 1;
        for(int i=0;i<n-1;i++){
            mxinc = nums[i+1]>nums[i] ? mxinc+1:1;
            mxdec = nums[i+1]<nums[i] ? mxdec+1:1;
            ans = max(ans,max(mxinc,mxdec));
        }
        return ans;
    }
};