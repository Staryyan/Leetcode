/**
 * If factor is (2, 5), then it can add a zero.
 */
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 1) {
        	return 0;
        }
        int total = 0;
        while (n / 5 != 0) {
        	n /= 5;
        	total += n;
        }
        return total;
    }
};