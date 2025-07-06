#include <vector>
#include <unordered_map>

class FindSumPairs {
private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> cnt;

public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int v : nums2) {
            cnt[v]++;
        }
    }
    
    void add(int index, int val) {
        int old = nums2[index];
        cnt[old]--;
        if (cnt[old] == 0) {
            cnt.erase(old);
        }
        nums2[index] += val;
        cnt[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int v : nums1) {
            ans += cnt[tot - v];
        }
        return ans;
    }
};

