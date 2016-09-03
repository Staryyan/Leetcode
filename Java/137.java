public class Solution {
    public int singleNumber(int[] nums) {
    	int ones = 0, twos = 0;
        for (int each : nums) {
        	ones = (ones ^ each) & ~twos;
        	twos = (twos ^ each) & ~ones;
        }
        return ones;
    }
}