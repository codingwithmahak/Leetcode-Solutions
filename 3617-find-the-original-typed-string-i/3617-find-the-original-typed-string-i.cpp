class Solution {
public:
    int possibleStringCount(string word) {
        int total = 1; // Start with the original string itself
        int n = word.size();
        
        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;
            
            // Count the length of the contiguous run of the same character
            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }
            
            // For a run of length count, we can have (count - 1) possibilities
            total += (count - 1);
        }
        
        return total;
    }
};
