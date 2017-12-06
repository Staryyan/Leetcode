#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int longestSubstring(string x, string y) {
		int Max = 0;
		vector<vector<int>> dp(x.length() + 1, vector<int>(y.length() + 1, 0));
		for (int i = 0; i < x.length(); i++) {
			for (int j = 0; j < y.length(); j++) {
				if (x[i] == y[j]) {
					dp[i + 1][j + 1] = 1 + dp[i][j];
					if (Max < dp[i + 1][j + 1]) {
						Max = dp[i + 1][j + 1];
					}
				}
			}
		}
		return Max;
	}
};

int main() {
	Solution so;
	cout << so.longestSubstring("introduction", "introductive") << endl;
}