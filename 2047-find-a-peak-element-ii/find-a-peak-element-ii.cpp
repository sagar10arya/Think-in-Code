class Solution {
    // finds the row index of the maximum element in a given column
    int findMaxIndex(vector<vector<int>>& mat, int n , int col)
    {
        int maxValue = -1, maxIndex=-1;
        for(int i=0; i<n; i++)
        {
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
public:
    // TC: O(n*logm) 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int maxRowIndex = findMaxIndex(mat,n, mid); // rowindex of maximum element in mid column
            int left = (mid-1 >= 0) ? mat[maxRowIndex][mid-1] : -1;
            int right = (mid+1 < m) ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return {maxRowIndex, mid};
            }
            // left is bigger --> higher value exists on left
            else if(mat[maxRowIndex][mid] < left) high = mid - 1; // move towards larger neighbor
            else low = mid + 1; // // right is bigger --> higher value exists on right
        }
        return {-1,-1};
    }
};