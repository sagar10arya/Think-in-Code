class Solution {
    // Time  : O(zero * one * limit)
    // Space : O(zero * one)
public:
    int MOD = 1e9+7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            zero+1,
            vector<vector<long long>>(one+1, vector<long long>(2,0))
        );

        // base cases
        for(int i=1;i<=min(zero,limit);i++)
            dp[i][0][0]=1;

        for(int j=1;j<=min(one,limit);j++)
            dp[0][j][1]=1;

        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){

                // end with 0
                for(int k=1;k<=limit && k<=i;k++){
                    dp[i][j][0] = (dp[i][j][0] + dp[i-k][j][1]) % MOD;
                }

                // end with 1
                for(int k=1;k<=limit && k<=j;k++){
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j-k][0]) % MOD;
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};