class Solution {
public:
    int minMoves(vector<int>& nums) {
        // sum of all elements - n* min of nums 
        // decrease 1 from each elemet and the sum of the subtraction of each is the answer
        return accumulate(nums.begin(),nums.end(),0) - nums.size()**min_element(nums.begin(),nums.end());
    }
};