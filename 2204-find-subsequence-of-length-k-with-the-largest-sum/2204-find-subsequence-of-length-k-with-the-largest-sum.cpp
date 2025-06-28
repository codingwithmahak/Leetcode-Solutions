#include <vector>
#include <algorithm>
#include <utility>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        std::vector<std::pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        std::sort(indexedNums.begin(), indexedNums.end(), std::greater<>());
        std::vector<std::pair<int, int>> topK(indexedNums.begin(), indexedNums.begin() + k);


        std::sort(topK.begin(), topK.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });

        std::vector<int> result;
        for (const auto& pair : topK) {
            result.push_back(pair.first);
        }

        return result;
    }
};
