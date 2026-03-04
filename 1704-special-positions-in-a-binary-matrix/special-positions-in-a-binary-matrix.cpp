class Solution {
public:
    // Brute
    // TC: O(n*m*(n+m))
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1)
                {
                    bool special = true;
                    // check row
                    for(int col=0; col<m; col++){
                        if(col != j && mat[i][col] == 1){
                            special = false;
                            break;
                        }
                    }

                    // check col
                    for(int row=0; row<n; row++){
                        if(row != i && mat[row][j] == 1){
                            special = false;
                            break;
                        }
                    }

                    if(special) cnt++;
                }
            }
        }

        return cnt;
    }
};