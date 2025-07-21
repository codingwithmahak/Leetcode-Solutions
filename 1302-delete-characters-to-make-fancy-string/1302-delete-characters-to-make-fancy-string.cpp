class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size(), j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < 2 || !(s[i] == s[j-1] && s[i] == s[j-2])) {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
    }
};
