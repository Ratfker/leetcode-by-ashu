class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0, hi = height.size() - 1, maxL = 0, maxR = 0, water = 0;
        while (lo < hi) {
            if (height[lo] < height[hi]) {
                height[lo] >= maxL ? maxL = height[lo] : water += maxL - height[lo];
                lo++;
            } else {
                height[hi] >= maxR ? maxR = height[hi] : water += maxR - height[hi];
                hi--;
            }
        }
        return water;
    }
};