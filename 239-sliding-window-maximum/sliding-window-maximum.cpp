class Solution {
public:
    // TC: O(n), SC: O(n-k+1) : Optimal
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // store indices
        for(int i=0; i<nums.size(); i++)
        {
            // remove elements oustide window
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();

            // remove smaller elements from back
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            // push current index
            dq.push_back(i);

            // window formed, store max in that window
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};