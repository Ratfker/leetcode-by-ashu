class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int lo = 0, hi = m;

        while (lo <= hi) {
            int cut1 = (lo + hi) / 2;       // partition index in nums1
            int cut2 = (m + n + 1) / 2 - cut1; // partition index in nums2

            // elements just left and right of each partition
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                // ✅ correct partition found
                if ((m + n) % 2 == 1)
                    return max(l1, l2);          // odd total → left max
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0; // even → average

            } else if (l1 > r2) {
                hi = cut1 - 1;   // cut1 too far right → move left
            } else {
                lo = cut1 + 1;   // cut1 too far left  → move right
            }
        }

        return 0.0;
    }
};