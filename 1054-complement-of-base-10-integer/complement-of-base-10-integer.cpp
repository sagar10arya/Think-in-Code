class Solution {
    // Complement = XOR with a mask of all 1s having same number of bits
    // Complement(n) = n ^ (2^k - 1) , k = number of bits in n
public:
    // TC: O(log n)  -> loop runs for number of bits in n
    // SC: O(1)
    int bitwiseComplement(int n) {
        // Edge case:
        // binary of 0 = "0"
        // complement = "1" -> answer = 1
        if(n == 0) return 1;

        int mask = 1;

        // Build a mask that becomes the next power of 2 greater than n
        // Example: n = 5 (101)
        // mask progression: 1 -> 2 -> 4 -> 8
        while(mask <= n){
            mask = mask << 1;   // left shift = multiply by 2
        }

        // Now mask is a power of two (1000 for example)
        // Subtracting 1 turns it into all 1s
        // Example: 1000 - 1 = 0111
        mask = mask - 1;

        // XOR with mask flips all bits
        // Example:
        //   101
        // ^ 111
        // -----
        //   010
        return n ^ mask;
    }
};