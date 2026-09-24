class Solution {
public:
    int SumDigits(int n){
        if(n<10) return n;
        int res = 0;
        while(n){
            res += n%10;
            n = n/10;
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(SumDigits(nums[i])==i) return i;
        }
        return -1;
    }
};