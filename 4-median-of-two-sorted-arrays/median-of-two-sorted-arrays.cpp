class Solution {
public:
    // brute force
    // time and space : O(n + m)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        vector<int> nums;
        while(i<n && j<m)
        {
            if(nums1[i] < nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while(i<n) nums.push_back(nums1[i++]);
        while(j<m) nums.push_back(nums2[j++]);
        
        int x = nums.size(); // size of merged array
        if(x % 2 == 0){
            return (nums[x/2] + nums[(x/2)-1]) / 2.0;
        } else{
            return nums[x/2];
        }
        return 0;
    }
};