class Solution {
public:
    // TC: O(2N), SC: O(N)
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;  // stack stores indices
        for(int i=0; i<=n; i++)
        {
            // at i == n, we pretend height = 0
            // this forces remaining bars to be processed
            int currHeight = (i == n) ? 0 : heights[i];

            // if current height is smaller,
            // we found right boundary for stack top
            while(!st.empty() && heights[st.top()] > currHeight)
            {
                int height = heights[st.top()];
                st.pop();

                int rightBoundary = i;
                int leftBoundary = st.empty() ? -1 : st.top();

                int width = rightBoundary - leftBoundary - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};