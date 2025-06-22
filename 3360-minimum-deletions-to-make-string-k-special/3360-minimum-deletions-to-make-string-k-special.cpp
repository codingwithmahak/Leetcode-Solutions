class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        vector<int> nonZeroFreq;
        for (int f : freq) {
            if (f > 0) nonZeroFreq.push_back(f);
        }

        sort(nonZeroFreq.begin(), nonZeroFreq.end());

        int minDeletions = INT_MAX;
        for (int i = 0; i < nonZeroFreq.size(); ++i) {
            int target = nonZeroFreq[i];
            int deletions = 0;

            for (int f : nonZeroFreq) {
                if (f > target + k) {
                    deletions += f - (target + k);
                } else if (f < target) {
                    deletions += f;
                }
            }

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
