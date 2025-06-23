#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int length = 1;

        while (count < n) {
            // Generate odd and even length palindromes in base 10
            for (int isEven = 0; isEven <= 1; ++isEven) {
                for (int half = pow10(length - 1); half < pow10(length); ++half) {
                    std::string halfStr = std::to_string(half);
                    std::string fullStr = halfStr;

                    if (isEven) {
                        std::reverse(halfStr.begin(), halfStr.end());
                        fullStr += halfStr;
                    } else {
                        std::reverse(halfStr.begin(), halfStr.end());
                        fullStr += halfStr.substr(1);
                    }

                    long long val = std::stoll(fullStr);
                    if (isKPalindrome(val, k)) {
                        sum += val;
                        count++;
                        if (count == n) return sum;
                    }
                }
            }
            ++length;
        }

        return sum;
    }

private:
    bool isKPalindrome(long long num, int k) {
        std::string baseK = "";
        while (num > 0) {
            baseK += ('0' + (num % k));
            num /= k;
        }
        std::string rev = baseK;
        std::reverse(rev.begin(), rev.end());
        return baseK == rev;
    }

    int pow10(int n) {
        int res = 1;
        while (n--) res *= 10;
        return res;
    }
};
