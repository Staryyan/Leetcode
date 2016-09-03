class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int aXorB = 0;
		for (int each : nums) {
			aXorB ^= each;
		}
		/**
		 * lowbit is the minimal bit
		 * and in this bit, a is different from b.
		 */
		int lowbit = aXorB & -aXorB;
		int a = 0, b = 0;
		for (int each : nums) {
			if (each & lowbit) {
				a ^= each;
			} else {
				b ^= each;
			}
		}
		return vector<int> {a, b};
	}
};
