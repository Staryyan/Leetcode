#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> topologicalSort(int n, vector<pair<int, int>>& edges) {
		queue<int> zeros;
		map<int, vector<int>> graph;
		map<int, int> in_degree;
		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i].first].push_back(edges[i].second);
			in_degree[edges[i].second]++;
		}
		for (int i = 0; i < n; i++) {
			if (in_degree[i] == 0) {
				zeros.push(i);
			}
		}
		vector<int> result;
		while (!zeros.empty()) {
			int start = zeros.front();
			result.push_back(start);
			zeros.pop();
			for (int i = 0; i < graph[start].size(); i++) {
				in_degree[graph[start][i]]--;
				if (in_degree[graph[start][i]] == 0) {
					zeros.push(graph[start][i]);
				}
			}
		}
		sort(result.begin(), result.end());
		return result;
	}
};

int main() {
	Solution so;
	vector<pair<int, int>> edges{{0, 1}, {0, 2}, {1, 2}, {3, 0}};
	vector<int> result = so.topologicalSort(4, edges);
	for (auto each : result) {
		cout << each << endl;
	}
}
