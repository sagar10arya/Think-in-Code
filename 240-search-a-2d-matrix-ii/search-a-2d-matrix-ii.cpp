class Solution {
    bool bs(vector<int>& matrix, int target){
        int n = matrix.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(matrix[mid] == target) return true;
            else if(matrix[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
public:
    // TC: O(n log m)  --> better
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            if(bs(matrix[i], target)) return true;
        }
        return false;
    }
};