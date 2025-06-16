class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = nums[0];
        int diff = -1;
        for (int i = 1; i < nums.size(); i++) {
            int value = nums[i];
            if (min > value)
                min = value;
            else
                diff = std::max(diff, value - min);
        }
        return diff == 0 ? -1 : diff;
    }
};
