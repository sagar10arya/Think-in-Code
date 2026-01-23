class Solution {
public:
    // Time --> O(n), Space --> O(1)
    // xor --> a ^ a = 0, a ^ 0 = a
    // if we xor all elements from 0-n and all elements in nums->everything cancels out excepts missing number
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            xor2 = xor2^nums[i]; // xor of all elements in nums
            xor1 = xor1 ^ (i+1); // xor from 1 to n
        }
        return xor1^xor2;
    }
};