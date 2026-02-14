class Solution {
    vector<int> previousSmallerElement(vector<int>& heights){
        int n = heights.size();
        vector<int> prev(n);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) prev[i] = -1;
            else prev[i] = st.top();

            st.push(i);
        }
        return prev;
    }

    vector<int> nextSmallerElement(vector<int>& heights){
        int n = heights.size();
        vector<int> next(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) next[i] = n;
            else next[i] = st.top();

            st.push(i);
        }
        return next;
    }

public:
    // TC: O(5N), SC: O(4N)
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int maxi = 0;
        int n = heights.size();
        for(int i=0; i<n; i++)
        {
            int width = heights[i] * (nse[i] - pse[i] - 1);
            maxi = max(maxi, width);
        }
        return maxi;
    }
};