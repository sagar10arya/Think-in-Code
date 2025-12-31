class Solution {

int findMax(vector<int>& piles){
    int maxi = INT_MIN;
    for(int i=0; i<piles.size(); i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

long long findTotalHours(vector<int>& piles, int hourly){
    long long totalHour = 0;
    for(int i=0; i<piles.size(); i++){
        // ceil(piles[i] / hourly)  === (piles[i] + hourly - 1) / hourly
        totalHour += ((long long)piles[i] + hourly - 1) / hourly;  // faster and avoid TLE
    }
    return totalHour;
}

public:
    // TC: O(n log (maxPile))
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;  // min possible speed
        int high = findMax(piles); // max possibe speed
        int ans = high; // worst case answer

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long totalHour = findTotalHours(piles, mid);
            if(totalHour <= h){
                ans = min(ans, mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};