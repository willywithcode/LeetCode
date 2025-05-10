class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        for (int i =0; i < s.length() ; i++) {
            if(cache.size() != 0) {
                if(cache.top() == '(' || cache.top() == '{' || cache.top() == '[') {
                    if(getOpposite(s[i]) == cache.top()){
                        cache.pop();
                        continue;
                    }
                }
            }
            cache.push(s[i]);
        }
        return cache.size() == 0;
    }
    char getOpposite(char c) {
        if (c == '(') return ')';
        else if (c == ')') return '(';
        else if (c == '{') return '}';
        else if (c == '}') return '{';
        else if (c == '[') return ']';
        else if (c == ']') return '[';
        return ' ';
    }
};