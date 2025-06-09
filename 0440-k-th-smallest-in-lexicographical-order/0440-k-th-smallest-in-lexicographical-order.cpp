class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1; // Start with the smallest number
        k--; // Decrease k to account for the current number

        while (k > 0) {
            int steps = calSteps(n, curr, curr + 1L); // Calculate steps to the next prefix
            if (steps <= k) {
                curr += 1; // Move to the next number
                k -= steps; // Decrease k by the number of steps
            } else {
                curr *= 10; // Move to the next level in the tree
                k -= 1; // Decrease k as we are moving down a level
            }
        }
        return curr; // Return the kth number
    }

private:
    int calSteps(int n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += std::min((long)n + 1, n2) - n1; // Count the number of valid numbers in the range
            n1 *= 10; // Move to the next level
            n2 *= 10; // Move to the next level
        }
        return (int)steps; // Return the total count of steps
    }
};
