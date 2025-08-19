class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r =0, l =0;
        int max = 0;
        while(r < s.length() && l < s.length()) {
            int check = checkSubstring(s, l, r);
            if(check == -1) {
                if(r - l +1 > max) max = r -l +1;
                ++r;
            }
            else {
                l = check + 1;
            }
        }   
        return max;   
    }
    int checkSubstring(string s, int l, int r) {
        auto lastChar = s[r];
        for (int i = l; i < r ; i ++) {
            if(s[i] == lastChar ) return i;
        }
        return -1;
    }
    
};