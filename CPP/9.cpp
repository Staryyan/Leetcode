#include <iostream>
#include <math.h>
using namespace std;
/**
 * Version 1.
 * Slight slow.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
        	return false;
        }
        int index = 0; int sum = x;
        while(sum != 0) {
        	index++;
        	sum /= 10;
        }
        while(x != 0) {
        	if ((x % 10) == (x / (int)pow(10, index - 1))) {
        		x %= (int)pow(10, index - 1);
        		x /= 10;
        		index -= 2;
        	} else {
        		return false;
        	}
        }
        return true;
    }
};
int main() {
	Solution so;
	cout << so.isPalindrome(110001);
}
/**
 * Version 2.
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int reverse = 0;
        int copy = x;
        
        while (copy != 0) {
            reverse = (reverse * 10) + (copy % 10);
            copy /= 10;
        }
        
        return (reverse == x);
    }
};
