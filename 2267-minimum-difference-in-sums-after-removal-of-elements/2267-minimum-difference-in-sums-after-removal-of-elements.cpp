#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long> leftSum(n + 1), rightSum(n + 1);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
        }
        leftSum[0] = sum;
        for (int i = n; i < 2 * n; i++) {
            sum += nums[i];
            maxHeap.push(nums[i]);
            sum -= maxHeap.top();
            maxHeap.pop();
            leftSum[i - n + 1] = sum;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int i = 3 * n - 1; i >= 2 * n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
        }
        rightSum[n] = sum;
        for (int i = 2 * n - 1; i >= n; i--) {
            sum += nums[i];
            minHeap.push(nums[i]);
            sum -= minHeap.top();
            minHeap.pop();
            rightSum[i - n] = sum;
        }
        long long ans = 1e15;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};
