class Solution {
public:
    // Brute: generating all substrings and check unique chars
    // TC: O(N^2), SC:O(256) ->all ascii chars
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<char> st; // new set every time

            for(int j = i; j < n; j++) {
                if(st.find(s[j]) != st.end()) {
                    break;
                }
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};