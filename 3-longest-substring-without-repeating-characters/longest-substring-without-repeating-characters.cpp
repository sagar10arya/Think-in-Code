class Solution {
public:
    // TC: O(N), SC:O(256) ->all ascii chars
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        vector<int> lastIndex(256, -1); // for every ascii char->stores where it was last seen

        int left = 0, right = 0;
        while(right < n)
        {   
            if(lastIndex[s[right]] >= left){
                left = lastIndex[s[right]] + 1;
            }

            lastIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};