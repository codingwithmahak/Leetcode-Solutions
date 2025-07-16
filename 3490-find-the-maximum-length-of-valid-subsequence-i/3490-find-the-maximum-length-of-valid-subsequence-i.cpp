class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int count_even = 0, count_odd = 0;
        int even_len = 0, odd_len = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                count_even++;
                even_len = max(even_len, odd_len + 1);
            } else {
                count_odd++;
                odd_len = max(odd_len, even_len + 1);
            }
        }
        int candidate_same = 0;
        if (count_even >= 2) candidate_same = max(candidate_same, count_even);
        if (count_odd >= 2) candidate_same = max(candidate_same, count_odd);
        int candidate_alt = max(even_len, odd_len);
        if (candidate_alt < 2) candidate_alt = 0;
        return max(candidate_same, candidate_alt);
    }
};
