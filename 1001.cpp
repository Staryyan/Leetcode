#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Solution {
public:
       int minDifference(vector<int> A) {
           int min_value = 2000;
           for (int i = 0; i < A.size(); i++) {
           		for (int j = i + 1; j < A.size(); j++) {
           			if (min_value > abs(A[i] - A[j])) {
           				min_value = abs(A[i] - A[j]);
           			}
           		}
           }
           return min_value;
       }
};

int main() {
	std::vector<int> A{-8, 10, 30, 10};
	Solution so;
	cout << so.minDifference(A) << endl;
}