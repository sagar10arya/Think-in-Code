class Solution {
public:
    // TC: O(N), SC: O(N)
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k == n) return "0";     // edge case: removing all digits
        stack<char> st;
        for(int i=0; i<n; i++)
        {
            // remove larger previous digit
            while(!st.empty() && k>0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0) {
            st.pop(); 
            k--;
        }   // if still k left, remove from end
        
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end()); // reverse as stack reverses order, time O(n)

        // removing leading zeroes
        int i = 0;
        while(i<res.length() && res[i] == '0') i++;
        res = res.substr(i);

        if(res.length() == 0) return "0";
        return res;
    }
};