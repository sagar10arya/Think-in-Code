class Solution {
public:
    // TC and SC : O(n)
    int minFlips(string s) {
        int n = s.size();
        string ss = s+s;    // Trick: duplicate the string to simulate rotations
        string alt1 = "";   // pattern starting with 0 -> 010101...
        string alt2 = "";      // pattern starting with 1 -> 101010...

        // Building alternating patterns of length 2n
        for(int i=0; i<2*n; i++)
        {
            alt1 += (i % 2 == 0 ? "0" : "1");
            alt2 += (i % 2 == 0 ? "1" : "0");
        }

        int diff1 = 0, diff2 = 0; // mismatches with alt1 and alt2
        int left = 0;
        int ans = INT_MAX;

        // Sliding window over ss
        for(int right = 0; right < 2*n; right++){
            // include current character in mismatch count
            if(ss[right] != alt1[right]) diff1++;
            if(ss[right] != alt2[right]) diff2++;

            // maintain window size = n
            if(right - left + 1 > n){
                // remove left element from mismatch count
                if(ss[left] != alt1[left]) diff1--;
                if(ss[left] != alt2[left]) diff2--;
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