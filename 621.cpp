#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> hash;
        for (auto each : tasks) {
        	hash[each]++;
        }
        priority_queue<int> availableQueue;
        queue<pair<int, int>> waitingQueue;
        for (auto each : hash) {
        	availableQueue.push(each.second);
        }
        int task;
        int costed = 0;
        int size = 0;
        pair<int, int> cur;
        while (!waitingQueue.empty() || !availableQueue.empty()) {
        	task = -1;
        	if (!availableQueue.empty()) {
			  	task = availableQueue.top();
        		availableQueue.pop();
        		task -= 1;
        	}
        	size = waitingQueue.size();
        	for (int i = 0; i < size; i++) {
        		cur = waitingQueue.front();
        		waitingQueue.pop();
        		cur.first -= 1;
        		if (cur.first == 0 || cur.first == -1) {
        			availableQueue.push(cur.second);
        		} else {
        			waitingQueue.push(cur);
        		}
        	}
        	if (task > 0) {
	        	waitingQueue.push(pair<int, int>{n, task});
        	}
        	costed++;
        }
        return costed;
    }
};

int main() {
	vector<char> task{'A', 'A', 'A', 'B', 'B', 'B'};
	Solution so;
	cout << so.leastInterval(task, 2) << endl;
	return 0;
}
