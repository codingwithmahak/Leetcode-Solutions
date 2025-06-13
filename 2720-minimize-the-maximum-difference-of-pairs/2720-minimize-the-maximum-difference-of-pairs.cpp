#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        
        auto canFormPairs = [&](int maxDiff) {
            int count = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    count++;
                    i++; 
                }
            }
            return count >= p;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        
        return left;
    }
};
