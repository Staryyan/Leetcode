class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
        	ans.push_back(vector<int>(i + 1, 1));
        	for (int j = 2; j < i + 1; j++) {
        		ans[i][j - 1] = ans[i - 1][j - 1] + ans[i - 1][j - 2];
        	}
        }
        return ans;
    }
};
