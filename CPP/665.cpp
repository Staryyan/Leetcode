#include <iostream>
#include <vector>
using namespace std;
bool checkPossibility(vector<int>& nums) {
	int front = 0;
	for (; front < nums.size() - 1; front++) {
		if (nums[front] > nums[front + 1]) {
			break;
		}
	}
	int back = nums.size() - 1;
	for (; back > 0; back--) {
		if (nums[back] < nums[back - 1]) {
			break;
		}
	}
	if (front == nums.size() - 1 or front == nums.size() - 2 or back == 1) {
		return true;
	} else {
		if (back - front == 1) {
			return nums[back] >= nums[front - 1] or nums[back + 1] >= nums[front];
		} else {
			return false;
		}
	}
}

int main() {
	vector<int> v{3,4,2,3};
	cout << checkPossibility(v) << endl;
	return 0;
}
