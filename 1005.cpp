#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minSum(vector<int>& A) {
		vector<int> dp(A.size(), 0);
		dp[0] = A[0];
		dp[1] = A[1];
		for (int i = 2; i < A.size(); i++){
			dp[i] = min(dp[i - 1], dp[i - 2]) + A[i];
		}
		return min(dp[A.size() - 1], dp[A.size() - 2]);
	}
};

int main() {
	vector<int> A{2, 5, 2};
	Solution so;
	cout << so.minSum(A) << endl;

}