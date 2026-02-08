class Solution {
public:
    // TC: O(4N), SC: O(2N)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;      //monotonic decreasing stack
        for(int i=2*n-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums[i%n]) st.pop();
            // compute ans only when i<n
            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            st.push(nums[i%n]);  // i%n for circular indexing
        }
        return ans;
    }
};