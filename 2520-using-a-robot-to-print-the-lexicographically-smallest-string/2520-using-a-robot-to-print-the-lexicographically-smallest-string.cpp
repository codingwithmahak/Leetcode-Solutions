#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    std::string robotWithString(std::string s) {
        int n = s.length();
        std::vector<char> minSuffix(n);
        minSuffix[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            minSuffix[i] = std::min(s[i], minSuffix[i + 1]);
        }

        std::string result;
        std::stack<char> t;
        int index = 0;

        while (index < n) {
            t.push(s[index]);

            while (!t.empty() && (index == n - 1 || t.top() <= minSuffix[index + 1])) {
                result += t.top();
                t.pop();
            }

            index++;
        }

        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
