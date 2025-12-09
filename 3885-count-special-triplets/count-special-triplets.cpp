class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int M = 1e9+7;
        unordered_map<int, int> valid_i;
        unordered_map<int, int> valid_j;
        int count = 0;

        for(int num : nums)
        {
            if(num%2==0){
                // if its valid k, we got our triplets
                count = (count + valid_j[num/2]) % M;
            }

            // if its valid j or not
            valid_j[num] = (valid_j[num] + valid_i[num*2]) % M;

            valid_i[num]++;
        }
        return count;
    }
};