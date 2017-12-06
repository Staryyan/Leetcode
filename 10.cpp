#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
    	dp[0][0] = true;
    	for (int i = 1; i <= p.size(); i++) {
    		if (p[i - 1] == '*') { dp[i][0] = dp[i - 2][0]; }
    	}
    	for (int i = 1; i <= p.size(); i++) {
    		for (int j = 1; j <= s.size(); j++) {
    			if (p[i - 1] != '*') {
    				if (p[i - 1] == '.' || p[i - 1] == s[j - 1]) {
    					dp[i][j] = dp[i - 1][j - 1];
    				} else {
    					dp[i][j] = false;
    				}
    			} else {
    				if (p[i - 2] == '.') {
    					int m = j;
    					while (m >= 0 && dp[i][j] == false) {
    						dp[i][j] = dp[i - 2][m];
    						m -= 1;
    					}
    				} else {
						dp[i][j] = dp[i - 2][j];
    					int m = j;
    					while (m > 0 && dp[i][j] == false) {
    						if (s[m - 1] == p[i - 2]) {
    							dp[i][j] = dp[i - 2][m - 1];
	    						m -= 1;
    						} else {
    							break;
    						}
    					}
    				}
    			}
    		}
    	}
    	return dp[p.size()][s.size()];
    }
};

int main() {
	Solution so;
	cout << so.isMatch("baabbbaccbccacacc", "c*..b*a*a.*a..*c") << endl;
	return 0;
}
