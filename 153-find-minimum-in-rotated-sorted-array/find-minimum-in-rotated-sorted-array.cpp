class Solution {
public:
    // Time:  O(log n)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // left half sorted
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]); // the smallest element in this half is nums[low]
                low = mid + 1;
            }
            else{ // right half sorted
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }   
        }
        return ans;
    }
};