class Solution {
public:
    // TC : O(n)
    // SC : O(1)
    int minFlips(string s) {
        int n = s.size();
        string ss = s+s;    // Trick: duplicate the string to simulate rotations
        int diff1 = 0, diff2 = 0; // mismatches with alt1 and alt2
        int left = 0;
        int ans = INT_MAX;

        // Sliding window over ss
        for(int right = 0; right < 2*n; right++){
            // Determine expected characters for both alternating patterns based on parity
            // Pattern1: even -> 0, odd -> 1
            // Pattern2: even -> 1, odd -> 0
            char expected1 = (right % 2 == 0) ? '0' : '1';
            char expected2 = (right % 2 == 0) ? '1' : '0';

            // include current character in mismatch count
            if(ss[right] != expected1) diff1++;
            if(ss[right] != expected2) diff2++;

            // maintain window size = n
            if(right - left + 1 > n){
                // Check the character leaving the window based on parity
                char leftExpected1 = (left % 2 == 0) ? '0' : '1';
                char leftExpected2 = (left % 2 == 0) ? '1' : '0';

                // remove left element from mismatch count
                if(ss[left] != leftExpected1) diff1--;
                if(ss[left] != leftExpected2) diff2--;
                left++;
            }

            // when window size becomes n -> valid rotation
            if(right - left + 1 == n){
                ans = min(ans, min(diff1, diff2));
            }
        }
        return ans;
    }
};