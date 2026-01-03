class Solution {
    private:
    int daysRequired(vector<int>& weights, int capacity)
    {
        int days = 1; // atleast 1 day needed
        int load = 0; // current load
        for(int i=0; i<weights.size(); i++)
        {
            if(load + weights[i] > capacity){
                days++;              // new day
                load = weights[i];   // start new day's load
            }
            else load += weights[i];
        }
        return days;
    }
public:
    // TC: O(n * log(sum-max+1))
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum=0, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int low=maxi; // capacity must be >= max single weight
        int high=sum;   // capacity <= sum of all weights
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(daysRequired(weights, mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};