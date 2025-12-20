class Solution {
public:
    int lower_bound(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    int upper_bound(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    
    // time --> 2 O(log n)
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lowerBound = lower_bound(nums, target);
        if(lowerBound == n || nums[lowerBound] != target ) return {-1, -1};
        int upperBound = upper_bound(nums, target);

        return {lowerBound, upperBound - 1};
    }
};