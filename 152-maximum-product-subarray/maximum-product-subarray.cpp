class Solution {
public:
    // TC -> O(n)
    //Sc -> O(1)
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prefix = 1;       // product from left to right
        int suffix = 1;       // product from right to left
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            // If product becomes zero, reset to 1
            // because zero breaks the subarray
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];   // multiply prefix with current element from front
            suffix *= nums[n - i - 1];   // multiply suffix with current element from back

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};