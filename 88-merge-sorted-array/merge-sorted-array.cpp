class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 has size (m + n), but only first m elements are valid
        int left = m-1;
        int right = 0;
        while(left >= 0 && right < n)
        {
            if(nums1[left] > nums2[right]){
                swap(nums1[left], nums2[right]);
                right++;
                left--;
            }
            else {
                // If nums1[left] <= nums2[right],
                // remaining elements are already in correct relative order
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.begin() + n);

        // Copy sorted nums2 into nums1 starting at index m
        for(int i=0; i<n; i++)
        {
            nums1[m+i] = nums2[i];
        }
    }
};