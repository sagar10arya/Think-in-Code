class Solution {
public:
    // Time: O(n² log n)
    // Space: O(1), not considering o/p storage
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i] == nums[i-1]) continue; // Skip duplicates for i
            int j = i+1;    // left pointer
            int k = n-1;    // right pointer
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;    // n a bigger sum → move left pointer to right
                else if(sum > 0) k--;   // need a smaller sum → move right pointer to left
                else{ // sum == 0
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;  // skip duplicates for j
                    while(j<k && nums[k] == nums[k+1]) k--;  // skip duplicates for k
                }

            }
        }

        return ans;
    }
};