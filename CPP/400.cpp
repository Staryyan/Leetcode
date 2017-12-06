#include <iostream>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {  
        long digit = 1, ith = 1, base = 9;
        while(n > digit * base) {
            n -= base * (digit++);
            ith += base;
            base *= 10;
        }
        return to_string(ith + (n-1)/digit)[(n-1)%digit] - '0';
    }  
};
int main() {
	Solution so;
	cout << so.findNthDigit(11) << endl;
	return 0;
}
