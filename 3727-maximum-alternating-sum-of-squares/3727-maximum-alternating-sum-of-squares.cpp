class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i] = nums[i]*-1;
        }
        sort(nums.begin(),nums.end());
        long long score = 0;
        int i=0,j=n-1;
        while(i<j){
            score += (long long)((nums[j]+nums[i])*(nums[j] - nums[i]));
            i++;j--;
        }
        if(n%2) score += (long long)(nums[i]*nums[i]);
        return score;
    }
};