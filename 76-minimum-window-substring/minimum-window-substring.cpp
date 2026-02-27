class Solution {
public:
    // Optimal
    // TC: O(n), SC: O(256)
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int cnt = 0; // no of matched characters
        int sIndex = -1, left = 0;
        int minLen = INT_MAX;
        vector<int> hash(256, 0);

        for(int i=0; i<t.size(); i++) hash[t[i]] ++;   // store frequency of t
        for(int right = 0; right < s.size(); right++)
        {
            if(hash[s[right]] > 0) cnt++;
            hash[s[right]]--; // decrease frequency (include in window)

            // shrink window if valid
            while(cnt == t.size()){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sIndex = left;
                }

                hash[s[left]]++;  // remove left character
                // if this character was necessary
                if(hash[s[left]] > 0){
                    cnt--;
                }
                left++;
            }     
        }
        
        if(sIndex == -1) return "";
        return s.substr(sIndex, minLen);
    }
};