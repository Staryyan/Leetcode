public class Solution {  
    /**
     * i = the first index of zero.
     * j = the first index of non-zero.
     * @param nums [the answer]
     */
    public void moveZeroes(int[] nums) {  
        int i=0;  
        int j=0;  
        while(j<nums.length) {
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
}