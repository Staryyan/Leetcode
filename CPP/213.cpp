class Solution {
public:
	 int robsplit(vector<int>& nums, int begin, int end) {
        if (end == begin) {
            return 0;
        } else if (end == begin + 1) {
            return nums[begin];
        } else {
            vector<int> ans(end, 0);
            ans[begin] = nums[begin];
            ans[begin + 1] = max(nums[begin], nums[begin + 1]);
            for (int i = begin + 2; i < end; ++i) {
                ans[i] = max(ans[i-1], ans[i-2] + nums[i]);
            }
            return ans[end - 1];
        }
    }
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) {
    		return 0;
    	} else if (nums.size() == 1){
    		return nums[0];
    	}
        return max(robsplit(nums, 0, nums.size() - 1), robsplit(nums, 1, nums.size()));
    }
};
