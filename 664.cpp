#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
    	if (s.length() == 0) { return 0; }
    	string unique_s;
    	unique_s += s[0];
    	for (int i = 1; i < s.length(); i++) {
    		if (s[i] != s[i - 1]) {
    			unique_s += s[i];
    		}
    	}
    	vector<vector<int>> matrix(unique_s.length(), vector<int>(unique_s.length(), 0));
    	return dp(matrix, unique_s, 0, unique_s.length() - 1);
    }

    int dp(vector<vector<int>> &matrix, string s, int i, int j) {
    	if (i == j) { return 1; }
    	if (i > j) { return 0; }
    	if (matrix[i][j] != 0) {
    		return matrix[i][j];
    	}
    	matrix[i][j] = dp(matrix, s, i + 1, j) + 1;
    	for (int k = i + 1; k <= j; k++) {
    		if (s[i] == s[k]) {
    			matrix[i][j] = min(matrix[i][j], dp(matrix, s, i, k - 1) + dp(matrix, s, k + 1, j));
    		}
    	}
    	return matrix[i][j];
    }

};

int main() {
	string s;
	cin >> s;
	Solution so;
	cout << so.strangePrinter(s) << endl;
	return 0;
}
