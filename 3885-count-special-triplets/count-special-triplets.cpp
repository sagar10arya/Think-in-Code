class Solution {
public:
    // Time -> O(2N), Space -> O(N)
    int specialTriplets(vector<int>& nums) {
        int M = 1e9+7;  // modulo value because the answer can be large
        int count = 0;

        // leftMap[x]  = how many times value x has appeared before current i
        unordered_map<int, int> leftMap;
        // rightMap[x] = how many times value x appears after current i
        unordered_map<int, int> rightMap; 

        // 1st fill rightMap with full frequency
        for(int num : nums)
        {
            rightMap[num]++;
        }

        for(int num : nums)
        {
            rightMap[num]--; // remove one occurrence of num from the right side

            int left = leftMap[num*2];
            int right = rightMap[num*2];

            // All pairs (i,j,k) = leftChoices * rightChoices
            // Multiply using 1LL to prevent integer overflow
            count = (count + (1LL * left * right)) % M;

            leftMap[num]++;
        }

        return count;
    }
};