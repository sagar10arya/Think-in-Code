class Solution {
public:
    // TC: O(n × m)
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(); // rows
        int m = mat[0].size(); // cols
        int maxi = 0;              // maximum number of 1s found so far
        int rowIndex = 0;          // row index with maximum 1s
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j = 0; j<m; j++)
            {
                if(mat[i][j] == 1) cnt +=1;
            }
            // If current row has more 1s than previous max
            if(cnt > maxi){
                maxi = cnt;
                rowIndex = i;
            }
        }
        return {rowIndex, maxi}; // [rowIndex, maximumOnes]
    }
};