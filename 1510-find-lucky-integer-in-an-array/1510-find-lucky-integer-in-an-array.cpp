#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        int largestLucky = -1;
        for (const auto& [key, value] : freq) {
            if (key == value) {
                largestLucky = max(largestLucky, key);
            }
        }
        return largestLucky;
    }
};
