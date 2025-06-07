#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution {
public:
    std::string clearStars(std::string s) {
        std::map<char, std::set<int>> char_positions;
        std::vector<bool> deleted_indices(s.length(), false);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') {
                char_positions[s[i]].insert(i);
            }
        }

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                deleted_indices[i] = true;

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (char_positions.count(c) && !char_positions[c].empty()) {
                        std::set<int>& indices_of_c = char_positions[c];

                        auto it = indices_of_c.upper_bound(i);

                        if (it != indices_of_c.begin()) {
                            --it;
                            int index_to_delete = *it;

                            deleted_indices[index_to_delete] = true;
                            indices_of_c.erase(it);

                            break; 
                        }
                    }
                }
            }
        }

        std::string result = "";
        result.reserve(s.length());
        for (int i = 0; i < s.length(); ++i) {
            if (!deleted_indices[i] && s[i] != '*') {
                result += s[i];
            }
        }
        return result;
    }
};
