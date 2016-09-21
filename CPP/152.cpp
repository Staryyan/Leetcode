/**
 * Dynamic Programming.
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int max3(int a, int b, int c) {
		return max(max(a, b), max(a, c));
	}
	int min3(int a, int b, int c) {
		return min(min(a, b), min(a, c));
	}
    int maxProduct(vector<int>& nums) {
    	int total = nums.size();
        if (total == 0) {
        	return 0;
        } else if (total == 1) {
        	return nums[0];
        }
        int global = nums[0];
        int max_local = nums[0];
        int min_local = nums[0];
        for (int i = 1; i < total; ++i) {
        	int max_copy = max_local;
        	max_local = max3(max_local * nums[i], nums[i], nums[i] * min_local);
        	min_local = min3(max_copy * nums[i], nums[i], nums[i] * min_local);
        	global = max(max_local, global);
        }
        return global;
    }
};
int main(int argc, char const *argv[]) {
	Solution so;
	vector<int> a{2, -1, -3, 1};
	cout << so.maxProduct(a) << endl;
	return 0;
}