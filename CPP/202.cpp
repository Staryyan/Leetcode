#include <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
    	if (n == 1 || n == 7) {
    		return true;
    	}
        int index = 0;
        int total = 0;
        while(n != 0) {
            index++;
            total += (n % 10) * (n % 10);
            n /= 10;
        }
        if (index == 1 && total != 1) {
        	return false;
        }
        return isHappy(total);
    }
};
int main() {
	Solution so;
	cout << so.isHappy(7) << endl;
}
