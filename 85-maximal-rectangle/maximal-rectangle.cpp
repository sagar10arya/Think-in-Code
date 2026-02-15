class Solution {
    // Time: O(n), Space: O(n)
    int largestRectangleArea(vector<int>& heights)
    {
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;
        for(int i=0; i<=n; i++)
        {
            int currHeight = (i==n) ? 0 : heights[i];
            while(!st.empty() && heights[st.top()] > currHeight){
                int height = heights[st.top()]; st.pop();
                int rightBoundary = i;
                int leftBoundary = st.empty() ? -1 : st.top();
                int width = rightBoundary - leftBoundary - 1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }

public:
    // TC: O(m*n) + O(2m)
    // SC: O(m*n) + O(n)
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> prefixSum(n, vector<int>(m,0));

        for(int j=0; j<m; j++)
        {
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                if(matrix[i][j] == '1') sum += 1;
                else sum = 0;
                prefixSum[i][j] = sum;
            }
        }

        for(int i=0; i<n; i++)
        {
            int largestHistRectangleArea = largestRectangleArea(prefixSum[i]);
            maxArea = max(maxArea, largestHistRectangleArea);
        }

        return maxArea;
    }
};