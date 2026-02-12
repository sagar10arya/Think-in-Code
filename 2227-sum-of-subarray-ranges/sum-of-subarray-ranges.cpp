class Solution {
    vector<int> getPreviousSmaller(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> prev(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) prev[i] = -1;
            else prev[i] = st.top();

            st.push(i);
        }
        return prev;
    }

    vector<int> getNextSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            // remove all elements greater OR equal to current
            // we use >= here to correctly handle duplicates
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            // If stack empty, no smaller element exists on right
            if(st.empty()) next[i] = n;
            else next[i] = st.top();

            st.push(i);
        }
        return next;
    }

    long long sumSubarrayMins(vector<int>& nums){
        int n = nums.size();
        long long sum = 0;

        vector<int> prev = getPreviousSmaller(nums);
        vector<int> next = getNextSmaller(nums);

        for(int i=0; i<n; i++)
        {
            int left = i - prev[i];
            int right = next[i] - i;

            int contribution = left * right;
            sum += (1LL * nums[i] * contribution);
        }
        return sum;
    }

    //*************** maximum *********************
    vector<int> getPreviousMaximum(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> prev(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) prev[i] = -1;
            else prev[i] = st.top();

            st.push(i);
        }
        return prev;
    }

    vector<int> getNextMaximum(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) next[i] = n;
            else next[i] = st.top();

            st.push(i);
        }
        return next;
    }

    long long sumSubarrayMaxs(vector<int>& nums){
        int n = nums.size();
        long long sum = 0;

        vector<int> prev = getPreviousMaximum(nums);
        vector<int> next = getNextMaximum(nums);

        for(int i=0; i<n; i++)
        {
            int left = i - prev[i];
            int right = next[i] - i;

            int contribution = left * right;
            sum += (1LL * nums[i] * contribution);
        }
        return sum;
    }
public:
    // TC: O(N), SC:O(1) : Optimal
    long long subArrayRanges(vector<int>& nums) {
        // Sum of subarray maximums - sum of subarray minimums
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};