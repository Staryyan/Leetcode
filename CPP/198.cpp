/**
 * Dynamic Programming.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else {
            vector<int> ans(n, 0);
            ans[0] = nums[0];
            ans[1] = max(nums[0], nums[1]);
            for (int i = 2; i < n; ++i) {
                ans[i] = max(ans[i-1], ans[i-2] + nums[i]);
            }
            return ans[n-1];
        }
    }
};