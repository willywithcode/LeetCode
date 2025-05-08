class Solution {
public:
    int romanToInt(string s) {
        map<char, int> symbolCaches;
        symbolCaches['I'] = 1;
        symbolCaches['V'] = 5;
        symbolCaches['X'] = 10;
        symbolCaches['L'] = 50;
        symbolCaches['C'] = 100;
        symbolCaches['D'] = 500;
        symbolCaches['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1) {
                result += symbolCaches[s[i]];
                continue;
            }
            if (symbolCaches[s[i]] < symbolCaches[s[i + 1]]) {
                result += symbolCaches[s[i + 1]] - symbolCaches[s[i]];
                ++i;
                continue;
            }
            result += symbolCaches[s[i]];
        }
        return result;
    }
};