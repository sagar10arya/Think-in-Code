class Solution {
public:
    // TC: O(log n)
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Edge case: only one element, that element itself is a peak
        if(n == 1) return 0;

        // Check if the last element is a peak
        // Last element has only one neighbor (left)
        if(nums[0] > nums[1]) return 0;

        // Check if the last element is a peak
        // Last element has only one neighbor (left)
        if(nums[n-1] > nums[n-2]) return n - 1;
        int low = 1, high = n-2;
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            // If the slope is increasing (left neighbor is smaller),
            // then a peak must exist on the right side
            else if(nums[mid] > nums[mid-1]) low = mid + 1;
            // otherwise, the slope is decreasing,
            // so a peak must exist on the left side
            else high = mid - 1;
        }
        return -1;
    }
};