class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int total = nums.size();
    	vector<int> v_ans(total, 0);
    	v_ans[0] = 1;
    	for (int i = 1; i < total; ++i) {
    		v_ans[i] = v_ans[i - 1] * nums[i - 1];
    	}
        int right = 1;
    	for (int i = total - 1; i > -1; i--) {
    		v_ans[i] *= right;
            right *= nums[i];
    	}
    	return v_ans;
    }
};
