class Solution {
public:
    // TC: O(log n)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];  // Edge case: only one element
        if(nums[0] != nums[1]) return nums[0];  // Edge case: unique element at the beginning
        if(nums[n-1] != nums[n-2]) return nums[n-1];    // Edge case: unique element at the en
        int low = 1, high = n-2;
        while(low <= high)
        {
            int mid = low + (high - low)/ 2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            // we are on the left and unique element is in the right
            if((mid%2==1 && nums[mid] == nums[mid-1]) || 
                (mid%2==0 && nums[mid] == nums[mid+1])){
                low = mid + 1;
            }
            // we are on the right and unique element is on the left
            else high = mid-1;
        }
        return -1;
    }
};