class Solution {
public:
    // Cantor's diagonalization principle
    // TC  : O(n)
    // SC : O(1)
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i=0; i<n; i++)
        {
            // Look at the diagonal element nums[i][i]
            // Flip the bit:
            // if '0' -> put '1'
            // if '1' -> put '0'
            // This ensures our new string differs from nums[i]
            // ensures the string differs from the i-th string at the i-th position
            if(nums[i][i] == '0') ans += "1";
            else ans += "0";
        }
        return ans;
    }
};