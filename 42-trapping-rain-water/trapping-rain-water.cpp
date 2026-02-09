class Solution {
public:
    // TC: O(N), SC: O(1) : Optimal
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int l = 0, r = n-1;
        int total = 0;

        while(l < r)
        {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax){ // left deciding factor(small)
                total += leftMax - height[l];
                l++;
            }
            else{ // right deciding factor(small)
                total += rightMax - height[r];
                r--;
            }
        }
        return total;
    }
};