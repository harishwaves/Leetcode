class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==i) continue;
            else k = nums[i] & k;
        }
        return max(k,0);
    }
};