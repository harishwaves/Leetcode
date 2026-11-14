class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> cumsum(n);
        cumsum[0] = nums[0];
        for(int i=1;i<n;i++){
            cumsum[i] = cumsum[i-1] + nums[i];
        }

        int i=0,j=0;
        int mnsum = INT_MAX;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                if(len<=r && len>=l){
                    int sum = cumsum[j] - (i>0 ? cumsum[i-1] : 0);
                    if(sum>0){
                        mnsum = min(mnsum,sum);
                        flag = 1;
                    }
                }
            }
        }
        if(!flag) return -1;
        return mnsum;
    }
};