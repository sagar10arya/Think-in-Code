class Solution {
    int subarraysWithSumLessThanEqualK(vector<int>& nums, int k)
    {
        if(k < 0) return 0; // edge case
        int left = 0, cnt = 0;
        unordered_map<int, int> mpp;

        for(int right = 0; right<nums.size(); right++)
        {
            mpp[nums[right]]++; // expand window
            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
            cnt += (right - left + 1);  // Count valid subarrays ending at right
        }
        return cnt;
    }

public:
    // Optimal
    // TC: O(N), SC: O(N)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithSumLessThanEqualK(nums, k)
                - subarraysWithSumLessThanEqualK(nums,k-1);
    }
};