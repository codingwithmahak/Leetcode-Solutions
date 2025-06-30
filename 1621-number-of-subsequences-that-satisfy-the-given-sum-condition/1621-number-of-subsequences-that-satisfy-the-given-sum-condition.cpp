class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Precompute powers of 2
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        
        int count = 0;
        int left = 0, right = n - 1;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                // If valid, count all subsequences formed by elements between left and right
                count = (count + power[right - left]) % MOD;
                left++;
            } else {
                // If not valid, move the right pointer to reduce the sum
                right--;
            }
        }
        
        return count;
    }
};
