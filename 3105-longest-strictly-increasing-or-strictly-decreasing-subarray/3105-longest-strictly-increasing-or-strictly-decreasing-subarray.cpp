class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mxinc = 1,mxdec = 1;
        int ans = 1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                mxinc++;
                ans = max(ans,mxinc);
            }
            else mxinc = 1;
            if(nums[i+1]<nums[i]){
                mxdec++;
                ans = max(ans,mxdec);
            }
            else mxdec = 1;
        }
        return ans;
    }
};