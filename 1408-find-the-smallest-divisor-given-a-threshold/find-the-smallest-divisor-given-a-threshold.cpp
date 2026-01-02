class Solution {
    long long sumByDivisor(vector<int>& nums, int div){
        long long sum=0;
        for(int i=0; i<nums.size(); i++)
        {
            // Integer ceil division:
            // ceil(a / b) = (a + b - 1) / b
            sum += (nums[i] + div - 1) / div;
        }
        return sum;
    }
public:
    // TC: O(n * log(max(nums)))
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(sumByDivisor(nums, mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};