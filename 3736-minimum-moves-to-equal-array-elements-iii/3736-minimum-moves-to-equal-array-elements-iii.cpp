class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        return *max_element(nums.begin(),nums.end())*n - accumulate(nums.begin(),nums.end(),0);
    }
};