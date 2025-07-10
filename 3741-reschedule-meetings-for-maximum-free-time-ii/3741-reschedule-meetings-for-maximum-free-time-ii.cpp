class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for (int i = 1; i < n; ++i)
            gaps.push_back(startTime[i] - endTime[i - 1]);
        gaps.push_back(eventTime - endTime.back());
        vector<int> maxLeft(n + 1), maxRight(n + 1);
        maxLeft[0] = gaps[0];
        for (int i = 1; i <= n; ++i)
            maxLeft[i] = max(maxLeft[i - 1], gaps[i]);
        maxRight[n] = gaps[n];
        for (int i = n - 1; i >= 0; --i)
            maxRight[i] = max(maxRight[i + 1], gaps[i]);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int currMeeting = endTime[i] - startTime[i];
            int adjGap = gaps[i] + gaps[i + 1];
            int maxOtherGap = 0;
            if (i > 0) maxOtherGap = max(maxOtherGap, maxLeft[i - 1]);
            if (i + 2 <= n) maxOtherGap = max(maxOtherGap, maxRight[i + 2]);
            if (currMeeting <= maxOtherGap)
                ans = max(ans, adjGap + currMeeting);
            else
                ans = max(ans, adjGap);
        }
        return ans;
    }
};
