class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_global = INT_MIN;
        int sum = 0;
        for (unsigned i = 0; i < nums.size(); ++i) {
        	if (sum >= 0) {
        		sum += nums[i];
        	} else {
        		sum = nums[i];
        	}
        	max_global = max(max_global, sum);
        }
        return max_global;
    }
};