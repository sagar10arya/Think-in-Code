class Solution {
public:
    // TC and SC: O(N) if unordered map(Worst case can degrade due to hash collisionsO(N*N))
    // TC and SC: O(N log N) if ordered map
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;   // prefixSum -> frequency
        mpp[0] = 1;     // Base case: prefix sum 0 has occurred once
        int preSum = 0, cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            preSum += nums[i];  // calculate the prefix sum that needs to be removed
            int remove = preSum - k;    // find how much we need to remove
            cnt += mpp[remove];     // if remove exists, add its frequency
            mpp[preSum] += 1;   // Update the frequency of the current prefix sum
        }
        return cnt;
    }
};