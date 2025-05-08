class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long cache = 0;
        int temp = x;
        while(temp > 0 ) {
            long num = temp % 10;
            cache = cache * 10 + num;
            temp /= 10;
        }
        return cache == x;
    }
};