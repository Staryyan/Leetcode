class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
        	if (nums[i] == val) {
        		zeros++;
        		continue;
        	} else {
        		nums[i - zeros] = nums[i];
        	}
        }
        return nums.size() - zeros;
    }

};