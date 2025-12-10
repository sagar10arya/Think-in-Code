class Solution {
public:
    // Time : O(N^2), Space: O(N^2)
    vector<int> generateNthRow(int row)
    {
        vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(ans);

        for(int col=1; col<row; col++){
            ans = ans * (row-col)/col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int row=1; row<=numRows; row++)
        {
            vector<int> temp = generateNthRow(row);
            ans.push_back(temp);
        }
        return ans;
    }
};