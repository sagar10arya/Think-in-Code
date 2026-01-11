class Solution {
public:
    // time : O(n1 + n2), space: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int ind2 = n/2, ind1 =ind2 - 1; // Median indices (0-based)
        int cnt = 0;
        int ind1ele = INT_MIN, ind2ele = INT_MIN; // To store median elements

        while(i<n1 && j<n2)
        {
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) ind1ele = nums1[i];
                if(cnt == ind2) ind2ele = nums1[i];
                cnt++; i++;
            } else {
                if(cnt == ind1) ind1ele = nums2[j];
                if(cnt == ind2) ind2ele = nums2[j];
                cnt++; j++;
            }
        }

        while(i<n1){
            if(cnt == ind1) ind1ele = nums1[i];
            if(cnt == ind2) ind2ele = nums1[i];
            cnt++; i++;
        }

        while(j<n2){
            if(cnt == ind1) ind1ele = nums2[j];
            if(cnt == ind2) ind2ele = nums2[j];
            cnt++; j++;
        }

        if(n%2 == 1) return ind2ele;

        return (double)(ind1ele + ind2ele) / 2.0;
    }
};