class Solution {
public:
    // TC: O(N)
    // SC: O(1)  (at most 3 types in map)
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        unordered_map<int, int> mpp;
        int left = 0;

        for(int right=0; right<n; right++)
        {
            mpp[fruits[right]]++;   // expand window
            // shrink window if more than 2 fruit types
            if(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            if(mpp.size() <= 2)
            {
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};