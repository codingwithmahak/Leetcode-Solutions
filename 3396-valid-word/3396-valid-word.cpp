#include <string>
#include <cctype> // For isalnum, isdigit, isalpha, tolower

class Solution {
public:
    bool isValid(std::string word) {
        if (word.length() < 3) {
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!std::isalnum(c)) {
                return false; // Contains characters other than digits and English letters
            }

            if (std::isalpha(c)) {
                char lower_c = std::tolower(c);
                if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
