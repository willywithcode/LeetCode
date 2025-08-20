class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while (s[index] == ' ') {
            ++index;
        }
        int sign = 1;
        if (s[index] == '-') {
            sign = -1;
            ++index;
        }
        else if(s[index] == '+') {
            sign = 1;
            ++index;
        }
          long long bound = (sign == 1) ? INT_MAX : -(long long)INT_MIN;
        
        long long result = 0;
        while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
            int digit = s[index] - '0';
            if (result > bound / 10 || (result == bound / 10 && digit > bound % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            ++index;
        }
        return static_cast<int>(sign * result);
    }
};