#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int>& nums) {
	map<int, int> hash_map;
	for (auto each : nums) {
		if (hash_map.find(each) == hash_map.end()) {
			hash_map[each] = 1;
		} else {
			hash_map[each]++;
		}
	}
	for (auto each : hash_map) {
		cout << each.first << " " << each.second << endl;
		if (each.second > nums.size() / 2) {
			return each.first;
		}
	}
	return 0;
}

int main() {
	vector<int> nums{2, 2};
	cout << majorityElement(nums) << endl;
}