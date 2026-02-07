class Solution {
public:
    // Time and space: O(N)
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            // pushing opening brackets
            if(ch == '(' || ch == '{' || ch == '[') st.push(s[i]);
            // handle closing brackets
            else{
                if(st.empty()) return false;
                if((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();   // remove matched pair
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();  // stack should be empty
    }
};