class Solution {
public:
    // Time: O(n logn) + O(N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++)
        {
            // ff merged is empty or current interval does not overlap
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                // overlapping: merge by extending the end time
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }



        return ans;
    }
};