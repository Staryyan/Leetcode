#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPartition(vector<int> A, int w) {
	     int total = 0;
	     sort(A.begin(), A.end());
	     int start = 0;
	     int end = A.size() - 1;
	     while (end >= start) {
	     	if (w >= A[end] + A[start]) {
	     		start++;
	     	}
     		end--;
     		total++;

	     }
	     return total;
	}
};

int main() {
	vector<int> A{2, 5, 4, 3};
	Solution so;
	cout << so.minPartition(A, 5) << endl;
}