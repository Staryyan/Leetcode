class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;  
        int j=0;  
        while(j<nums.size()) {
        	if (nums[j] != 0) {
        		if (j != i) {
        			nums[i++] = nums[j];
        			nums[j] = 0;
        		} else {
        			i++;
        		}
        	}
        	j++;
        }
    }
};