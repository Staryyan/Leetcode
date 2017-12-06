#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int>> nearestZero(vector<vector<int>>& A) {
		vector<vector<int>> graph = A;
		queue<pair<int, int>> search;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[0].size(); j++) {
				if (A[i][j] == 0) {
					search.push(pair<int, int>(i, j));
					graph[i][j] = 0;
				} else {
					graph[i][j] = 100000;
				}
			}
		}
		pair<int, int> top;
		while (!search.empty()) {
			top = search.front();
			search.pop();
			int i = top.first;
			int j = top.second;
			if (top.first > 0) {
				if (graph[i - 1][j] > graph[i][j] + 1) {
					graph[i - 1][j] = graph[i][j] + 1;
					search.push(pair<int, int>(i - 1, j));
				}
			}
			if (top.first < A.size() - 1) {
				if (graph[i + 1][j] > graph[i][j] + 1) {
					graph[i + 1][j] = graph[i][j] + 1;
					search.push(pair<int, int>(i + 1, j));
				}
			}
			if (top.second > 0) {
				if (graph[i][j - 1] > graph[i][j] + 1) {
					graph[i][j - 1] = graph[i][j] + 1;
					search.push(pair<int, int>(i, j - 1));
				}
			}
			if (top.second < A[0].size() - 1) {
				if (graph[i][j + 1] > graph[i][j] + 1) {
					graph[i][j + 1] = graph[i][j] + 1;
					search.push(pair<int, int>(i, j + 1));
				}
			}
		}
		return graph;
	}
};

int main() {
	vector<vector<int>> A{{1, 1, 1},
						  {0, 1, 1},
						  {0, 0, 1}};
	Solution so;
	auto result = so.nearestZero(A);
	for (auto each : result) {
		for (auto one : each) {
			cout << one << " ";
		}
		cout << endl;
	}
	return 0;
}
