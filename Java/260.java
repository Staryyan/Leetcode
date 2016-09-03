public class Solution {
    public int[] singleNumber(int[] nums) {
        int total = 0;
        for (int each : nums) {
            total ^= each;
        }
        int lowbit = total & -total;
        int a = 0, b = 0;
        for (int each : nums) {
            if ((each & lowbit) != 0) {
                a ^= each;
            } else {
                b ^= each;
            }
        }
        int[] ans = new int[2];
        ans[0] = a; ans[1] = b;
        return ans;
    }
}