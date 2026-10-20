class Solution {
public:
    bool isRotationPossible(vector<int> v1, vector<int> v2) {
        if (v1.size() != v2.size()) return false;
        v2.insert(v2.end(), v2.begin(), v2.end());
        return search(v2.begin(), v2.end(), v1.begin(), v1.end()) != v2.end();
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool validK = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n && validK; start += k) {
                vector<int> block(nums.begin() + start, nums.begin() + start + k);
                vector<int> target(sortedNums.begin() + start, sortedNums.begin() + start + k);

                if (!isRotationPossible(block, target)) {
                    validK = false;
                    break;
                }
                // A rotation that joins the already sorted prefix must start
                // with the block's minimum. Its final value is the maximum.
                int currMin = *min_element(block.begin(), block.end());
                int currMax = *max_element(block.begin(), block.end());
                if (prevMax > currMin) {
                    validK = false;
                    break;
                }
                prevMax = currMax;
            }
            if (validK) ans += k;
        }
        return ans;
    }
};