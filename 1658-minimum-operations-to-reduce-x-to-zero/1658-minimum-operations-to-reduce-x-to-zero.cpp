class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int tgt = sum - x;
        if(tgt<0) return -1;
        if(tgt==0) return n;
        int left = 0,add=0,largest=-1;
        for(int rgt=0;rgt<n;rgt++){
            add += nums[rgt];
            while(left<=rgt && add>tgt){
                add -= nums[left++];
            }
            if(add==tgt){
                largest = max(largest,rgt-left+1);
            }
        }
        return largest==-1?-1 : n-largest;
    }
};