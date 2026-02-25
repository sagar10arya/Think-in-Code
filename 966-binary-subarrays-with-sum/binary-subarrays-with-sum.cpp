class Solution {
    int atmost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int cnt = 0, left = 0, sum = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while(sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            if(sum <= goal){
                cnt += (right - left + 1);
            }
        }
        return cnt;
    }

public:
    // TC: O(2N), SC: O(1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};