/**
 * Lime limited!
 */
class Solution {
public:
	int hasZero(int temp) {
		int zeors = 0;
		while (temp != 0) {
			if (temp % 10 == 1) {
				zeros++;
			}
			temp /= 10;
		}
		return zeros;
	}
    int countDigitOne(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
        	total += hasZero(i);
        }
        return total;
    }
};
