// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // time --> O(log n)
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        int firstBad = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            // ff mid version is bad, it could be the first bad version
            if(isBadVersion(mid)){ // true
                firstBad = mid;
                high = mid - 1;     // search left half
            }
            else{
                // mid version is good,first bad version must be after mid
                low = mid + 1;
            }
        }
        return firstBad;
    }
};