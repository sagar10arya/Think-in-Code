class Solution {
public:
    // TC: O(N), SC: O(1)
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0, r = 0;

        while(r < nums.size() - 1)
        {
            int farthest = 0;
            for(int j = l; j<=r; j++)
            {
                farthest = max(farthest, j+nums[j]);
            }
            l = r+1;
            r = farthest;
            jumps += 1;
        }
        return jumps;
    }
};