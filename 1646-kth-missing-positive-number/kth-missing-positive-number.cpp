class Solution {
public:
    // TC: Time Complexity: O(N)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            if(arr[i] <= k) k++;    // if current number is <= to k, increment k
            else break;
        }
        return k;    // final value of k which is the missing number
    } 
};