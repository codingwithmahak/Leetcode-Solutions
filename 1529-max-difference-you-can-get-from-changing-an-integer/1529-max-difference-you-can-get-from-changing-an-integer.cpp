class Solution {
public:
    int maxDiff(int num) {
        string strNum = to_string(num);
        string maxStr = strNum, minStr = strNum;

        char toReplaceMax = 0;
        for (char c : strNum) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        char toReplaceMin = 0;
        if (strNum[0] != '1') {
            toReplaceMin = strNum[0];
            for (char &c : minStr) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            for (int i = 1; i < strNum.size(); ++i) {
                if (strNum[i] != '0' && strNum[i] != '1') {
                    toReplaceMin = strNum[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 0; i < minStr.size(); ++i) {
                    if (minStr[i] == toReplaceMin) minStr[i] = '0';
                }
            }
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);
        return maxNum - minNum;
    }
};
