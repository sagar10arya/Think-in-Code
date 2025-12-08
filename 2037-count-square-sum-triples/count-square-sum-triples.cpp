class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        for(int a = 1; a<=n; a++)
        {
            for(int b=1;b<=n; b++)
            {
                int x = a*a + b*b;
                int c = sqrt(x);
                if(x == c*c && c <= n) count++;
            }
        }
        return count;
    }
};