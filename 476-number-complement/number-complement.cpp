class Solution {
public:
    // TC: O(log n)
    int findComplement(int num) {
        if(num == 0) return 1; //edge case: binary of 0 : "0", complement = 1

        long long mask = 1;
        while(mask <= num) mask = mask << 1;
        mask = mask - 1;

        return num ^ mask;
    }
};