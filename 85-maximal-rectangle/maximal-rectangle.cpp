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
    // SC: O(m)  // space optimized
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        
        vector<int> height(m, 0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};