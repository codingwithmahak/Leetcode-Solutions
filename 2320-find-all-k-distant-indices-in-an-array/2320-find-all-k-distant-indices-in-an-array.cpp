#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> result;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (std::abs(i - j) <= k && nums[j] == key) {
                    result.push_back(i);
                    break;
                }
            }
        }
        
        return result;
    }
};
