class Solution {
public:
    // TC: O(N), SC:O(3) : Optimal
    int numberOfSubstrings(string s) {
        int cnt = 0;
        vector<int> lastSeen(3, -1); // store the last index where a,b,c last appears
        for(int i=0; i<s.size(); i++)  // i is ending index for a substring
        {   
            // if char is a : 'a' - 'a' = 0
            // if char is b : 'b' - 'a' = 1
            // if char is c : 'c' - 'a' = 2
            lastSeen[s[i] - 'a'] = i;   // mapping 'a':0, 'b':1, 'c':2
            
            cnt += min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
        }
        return cnt;
    }
};