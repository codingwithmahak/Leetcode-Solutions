#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        std::vector<std::vector<int>> dp(k, std::vector<int>(k, 0));
        std::vector<int> seen(k, 0);
        int ans = 1;
        for (int x : nums) {
            int cur = x % k;
            std::vector<int> upd(k, 0);
            for (int r = 0; r < k; ++r) {
                int prev = (r - cur + k) % k;
                if (dp[r][prev] > 0) {
                    upd[r] = std::max(upd[r], dp[r][prev] + 1);
                } else if (seen[prev] > 0) {
                    upd[r] = std::max(upd[r], 2);
                }
            }
            seen[cur]++;
            for (int r = 0; r < k; ++r) {
                dp[r][cur] = std::max(dp[r][cur], upd[r]);
                ans = std::max(ans, dp[r][cur]);
            }
        }
        return ans;
    }
};
