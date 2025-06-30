#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        
        int maxLength = 0;
        
       
        for (const auto& entry : countMap) {
            int num = entry.first;
            if (countMap.find(num + 1) != countMap.end()) {
                maxLength = max(maxLength, entry.second + countMap[num + 1]);
            }
        }
        
        return maxLength;
    }
};
