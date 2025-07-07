#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events) {
        std::sort(events.begin(), events.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        int attended = 0;
        int n = events.size();
        int i = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int day = 1; day <= 100000; ++day) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);
                ++i;
            }

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();
                ++attended;
            }
        }

        return attended;
    }
};
