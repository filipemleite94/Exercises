class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size(m+n);
        int i(size), j(0), k(0);
        while(i-->n)
            nums1[i] = nums1[i-n];
        i = n;
        while(i<size&&j<n)
            nums1[k++] = nums1[i]<nums2[j] ? nums1[i++]:nums2[j++];
        while(j<n)
            nums1[k++] = nums2[j++];
    }
};