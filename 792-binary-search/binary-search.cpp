class Solution {
public:
    // time Complexity: O(log n)
    // space Complexity: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low + high) / 2;
            // int mid = low + (high - low) / 2;  // avoids integer overflow when low and high are very large
            if(nums[mid] < target){
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                // nums[mid] == target
                return mid;
            }
        }
        return -1;
    }
};