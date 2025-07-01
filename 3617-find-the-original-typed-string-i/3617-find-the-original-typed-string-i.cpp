class Solution {
public:
    int possibleStringCount(string word) {
        int total = 1; 
        int n = word.size();
        
        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;
            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }
            
        
            total += (count - 1);
        }
        
        return total;
    }
};
