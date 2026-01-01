class Solution {
private:
    // Checks if it is possible to make `m` bouquets
    // using flowers that bloom on or before `day`
    bool possible(vector<int>& bloomDay, int m, int k, int day)
    {
        int cnt = 0;// counts consecutive bloomed flowers 
        int noOfBouquets=0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day) cnt++; // flower boomed
            else{
                noOfBouquets += cnt / k;
                cnt = 0;
            }
        }
        noOfBouquets += cnt / k;
        if(noOfBouquets >= m) return true;
        else return false;
    }

public:
    // Time Complexity:
    // O(n * log (max-min+1))
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1LL * m * k;
        if(val > n) return -1;

        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;

        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};