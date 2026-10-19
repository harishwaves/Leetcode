class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = 0,count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<target) idx++;
            if(nums[i]==target) count++;
        }
        vector<int> ans;
        while(count--){
            ans.push_back(idx++);
        }
        return ans;
    }
};