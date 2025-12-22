class Solution {
public:
    // TC --> O(log n)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // Case 1: Duplicates at the boundaries
            // Cannot determine which half is sorted
            // Safely shrink the search space
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                // We must still consider nums[low] as a candidate minimum
                // what if there is a single element
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};