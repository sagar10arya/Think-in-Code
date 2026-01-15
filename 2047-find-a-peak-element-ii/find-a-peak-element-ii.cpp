class Solution {
public:
    // TC: O(n*m) --> brute
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n ;i++){
            for(int j=0;j<m;j++)
            {
                int curr = mat[i][j];

                int top = (i>0) ? mat[i-1][j] : -1;
                int bottom = (i < n-1) ? mat[i+1][j] : -1;
                int left = (j>0) ? mat[i][j-1] : -1;
                int right = (j<m-1) ? mat[i][j+1] : -1;

                if(curr > top && curr > bottom &&
                    curr > left && curr > right) return {i,j};
            }
        }
        return {-1,-1};
    }
};