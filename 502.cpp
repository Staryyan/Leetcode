#include <queue>
#include <iostream>
#include <vector>

using namespace std;
class ComparisonInt {
public:
    bool operator() (int a, int b) {
    	return a < b;
    }
};

class ComparisonVec {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.first > b.first;
	}
};

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> Profits, vector<int> Capital) {
		priority_queue<int, vector<int>, ComparisonInt> ProfitsQueue;
		priority_queue<pair<int, int>, vector<pair<int, int>>, ComparisonVec> CapProQueue;
		for (int i = 0; i < Profits.size(); i++) {
			CapProQueue.push(pair<int, int>(Capital[i], Profits[i]));
		}
		while (k != 0) {
			while (!CapProQueue.empty() && CapProQueue.top().first <= W) {
				ProfitsQueue.push(CapProQueue.top().second);
				CapProQueue.pop();
			}
			if (ProfitsQueue.empty()) { return W; }
			W += ProfitsQueue.top();
			ProfitsQueue.pop();
			k--;
		}
		return W;
    }
};



int main() {
	Solution so;
	cout << so.findMaximizedCapital(2, 0, vector<int>{1,2,3}, vector<int>{0,1,1}) << endl;;
	return 0;
}
