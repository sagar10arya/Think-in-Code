class Solution {
    // return no of subarray needed if max allowed subarray is "maxAllowedSum"
    int countSubarrays(vector<int>& nums, int maxAllowedSum)
    {
        int subarrayCount = 1;      // at least one subarray
        long long currentSum = 0;   // sum of current subarray
        for(int i=0; i<nums.size(); i++)
        {
            if(currentSum + nums[i] <= maxAllowedSum){
                currentSum += nums[i];
            }
            else{
                subarrayCount++;
                currentSum = nums[i];
            }
        }
        return subarrayCount;
    }
public:
    // TC: O(n* log(high - low + 1))
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int requiredSubarrays  = countSubarrays(nums, mid);
            if(requiredSubarrays  <= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid+1;
        }
        return ans;
    }
};