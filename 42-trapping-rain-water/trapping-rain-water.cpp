class Solution {
    vector<int> prefixMaximum(vector<int>& height, int n){
        vector<int> prefix(n);
        prefix[0] = height[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = max(prefix[i-1], height[i]);
        }
        return prefix;
    }

    vector<int> suffixMaximum(vector<int>& height, int n){
        vector<int> suffix(n);
        suffix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        return suffix;
    }

public:
    // TC: O(3N), SC: O(2N)
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax = prefixMaximum(height, n);
        vector<int> suffixMax = suffixMaximum(height, n);
        int total = 0;
        for(int i=0; i<n; i++)
        {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};