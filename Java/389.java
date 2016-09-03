public class Solution {
    public char findTheDifference(String s, String t) {
    	char[] ch_s = s.toCharArray();
    	char[] ch_t = t.toCharArray();
        char left = 0;
        for (char each : ch_s) {
        	left ^= each;
        }
        for (char each : ch_t) {
        	left ^= each;
        }
        return left;
    }
}