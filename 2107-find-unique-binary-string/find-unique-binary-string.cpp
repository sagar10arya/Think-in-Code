class Solution {
    // Time: O(2^n)
    // Space: recursion stack
public:
    string ans;
    unordered_set<string> st;

    void solve(string curr, int n){
        if(curr.size() == n)
        {
            if(st.count(curr) == 0){
                ans = curr;
            }
            return;
        }
        if(!ans.empty()) return;

        solve(curr + "0", n);
        solve(curr + "1", n);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(auto &x: nums){
            st.insert(x);
        }
        solve("", n);
        return ans;
    }
};