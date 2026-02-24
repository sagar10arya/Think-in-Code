class Solution {
public:
    // Optimal
    // TC: O(N), SC:O(26)
    int characterReplacement(string s, int k) {
        int maxLen = 0;
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        for(int right = 0; right < s.size(); right++)
        {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            int replacements = (right-left+1) - maxFreq;

            if(replacements > k){
                freq[s[left] - 'A']--;
                left++;
            }

            if(replacements <= k){
                maxLen = max(maxLen, (right-left+1));
            }
        }
        return maxLen;
    }
};