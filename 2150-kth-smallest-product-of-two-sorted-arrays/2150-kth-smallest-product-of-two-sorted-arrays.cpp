#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

private:
    long long countLessEqual(const vector<int>& nums1, const vector<int>& nums2, long long x) {
        long long count = 0;

        for (int a : nums1) {
            if (a == 0) {
                if (x >= 0) count += nums2.size();
                // else: 0 * any > x, contribute nothing
            } else if (a > 0) {
                // b <= x / a
                int l = 0, r = nums2.size();
                while (l < r) {
                    int m = (l + r) / 2;
                    if ((long long)a * nums2[m] <= x) l = m + 1;
                    else r = m;
                }
                count += l;
            } else { // a < 0
                // b >= ceil(x / a)
                int l = 0, r = nums2.size();
                while (l < r) {
                    int m = (l + r) / 2;
                    if ((long long)a * nums2[m] <= x) r = m;
                    else l = m + 1;
                }
                count += nums2.size() - l;
            }
        }

        return count;
    }
};
