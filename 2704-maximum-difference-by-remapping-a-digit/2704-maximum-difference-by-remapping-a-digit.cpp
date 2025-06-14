#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    int minMaxDifference(int num) {
        std::string s = std::to_string(num);
        long long max_num = -1, min_num = -1;

        for (int i = 0; i < 10; ++i) {
            std::string temp = s;
            for (char& c : temp) {
                if (c - '0' == i) {
                    c = '9';
                }
            }
            max_num = std::max(max_num, std::stoll(temp));


            temp = s;
            for (char& c : temp) {
                if (c - '0' == i) {
                    c = '0';
                }
            }
            if(min_num == -1) min_num = std::stoll(temp);
            else min_num = std::min(min_num, std::stoll(temp));
        }
        return max_num - min_num;
    }
};
