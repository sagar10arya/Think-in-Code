class Solution {
public:
    // TC: O(2N), SC: O(1)
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int n = nums.size();
        int left = 0, right = 0;
        int cnt0 = 0;
        while(right < n)
        {
            if(nums[right] == 0) cnt0++;    // Expand window
            // Shrink window if invalid
            while(cnt0 > k)
            {
                if(nums[left] == 0) cnt0--;
                left++;
            }
            if(cnt0 <= k)
            {
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }


        return maxLen;
    }
};