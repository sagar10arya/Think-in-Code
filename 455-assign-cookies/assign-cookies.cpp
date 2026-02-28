class Solution {
public:
    // TC: O(n log n + m log m + n), SC: O(1)
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;   // child greed
        int cookie = 0;  // cookie

        while(child < g.size() && cookie <s.size())
        {
            if(g[child] <= s[cookie]){
                child++;    // child satisfied
            }
            cookie++;   // move to next cookie
        }
        return child;   // number of satisfied children
    }
};