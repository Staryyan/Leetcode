public class Solution {
    public int singleNumber(int[] nums) {
    	int ans = 0;
        for (int each : nums) {
        	ans ^= each;
        }
        return ans;
    }
}