class Solution {
public:
    // TC: O(n), space: O(1)
    int fib(int n) {
        if(n <= 1) return n;
        int a = 0; // fib 0
        int b = 1; // fib 1
        for(int i=2; i<=n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;  // b always holds fib(n)
    }
};