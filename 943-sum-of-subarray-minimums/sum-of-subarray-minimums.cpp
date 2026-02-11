class Solution {
    // finds Previous Smaller Element index for every element
    // For each index i, we find the nearest index j < i such that arr[j] < arr[i]
    // If no such index exists, we store -1
    vector<int> getPreviousSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n);    // prev[i] will store index of previous smaller element
        stack<int> st;          // stack stores indices, not values

        for(int i=0; i<n; i++)
        {
            // Remove all elements from stack that are strictly greater than current element
            // Because they cannot be previous smaller for arr[i]
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            // If stack becomes empty, no smaller element exists on left
            if(st.empty()) prev[i] = -1;
            else prev[i] = st.top();    // top now holds index of previous smaller element

            // Push current index to stack
            // It may serve as previous smaller for future element
            st.push(i);
        }
        return prev;
    }

    // finds Next Smaller Element index for every element
    // For each index i, we find nearest index j > i such that arr[j] < arr[i]
    // If none exists, we store n (acts as boundary)
    vector<int> getNextSmaller(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> next(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            // remove all elements greater OR equal to current
            // we use >= here to correctly handle duplicates
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            // If stack empty, no smaller element exists on right
            if(st.empty()) next[i] = n;
            else next[i] = st.top();

            st.push(i);
        }
        return next;
    }

public:
    // TC: O(N), SC: O(N) : Optimal
    // for each element arr[i], calculate how many subarrays
    // it acts as minimum and add its contribution
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = (int) (1e9 + 7);
        int n = arr.size();

        // Step 1: Get boundaries
        vector<int> prev = getPreviousSmaller(arr);
        vector<int> next = getNextSmaller(arr);

        long long sum = 0;

        // Step 2: Calculate contribution of each element
        for(int i=0; i<n; i++)
        {
            long long left = i - prev[i];   // Distance to previous smaller
            long long right = next[i] - i;  // Distance to next smaller

            // total subarrays where arr[i] is minimum:
            // left choices for start * right choices for end
            long long contribution = (left * right) % MOD;
            
            sum = (sum + (arr[i] * contribution) % MOD) % MOD;
        }
        return sum;
    }
};