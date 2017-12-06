#include <iostream>

using namespace std;

int main() {
	int array[51][51][51] = {};
    int threshold = 1000000007;
	int m, n, N, i, j;
	cin >> m >> n >> N >> i >> j;
	for (int step = 1; step <= N; step++) {
		for (int mi = 0; mi < m; mi++) {
			for (int ni = 0; ni < n; ni++) {
				array[mi][ni][step] = ((mi == 0 ? 1 : array[mi - 1][ni][step - 1]) % threshold 
									 + (mi == m - 1 ? 1 : array[mi + 1][ni][step - 1]) % threshold
									 + (ni == 0 ? 1 : array[mi][ni - 1][step - 1]) % threshold
									 + (ni == n - 1 ? 1 : array[mi][ni + 1][step - 1]) % threshold) % threshold;
			}
		}
	}
	cout << array[i][j][N];
}


// class Solution {
// public:
//     struct Node {
//         int i, j;
//         int times;
//         Node(int _i, int _j, int _times): i(_i), j(_j), times(_times) {}
//     };

//     bool validate(int m, int n, int i, int j) {
//         return !(i < 0 || j < 0 || i == m || j == n);
//     }

//     int findPaths(int m, int n, int N, int i, int j) {
//         Node start(i, j, 0);
//         queue<Node> nodeQueue;
//         nodeQueue.push(start);
//         int total = 0;
//         int threshold = 1000000000 + 7;
//         while (!nodeQueue.empty()) {
//             Node tmp = nodeQueue.front();
//             nodeQueue.pop();
//             if (tmp.times > N) { continue; }
//             if (validate(m, n, tmp.i, tmp.j)) {
//                 if (tmp.times == N) { continue; }
//                 nodeQueue.push(Node(tmp.i, tmp.j + 1, tmp.times + 1));
//                 nodeQueue.push(Node(tmp.i, tmp.j - 1, tmp.times + 1));
//                 nodeQueue.push(Node(tmp.i + 1, tmp.j, tmp.times + 1));
//                 nodeQueue.push(Node(tmp.i - 1, tmp.j, tmp.times + 1));
//             } else {
//                 total += 1;
//                 total %= threshold;
//             }
//         }
//         return total;
//     }
// };