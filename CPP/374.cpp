// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
#include <iostream>
using namespace std;
int check = 40;
int guess(int num) {
    if (num < check) {
        return -1;
    }
    if (num > check) {
        return 1;
    }
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1; int high = n;
        while (true) {
            int mid = (low + high) / 2;
            cout << mid << endl;
            int state = guess(mid);
            if (state == 0) {
                return mid;
            } else if (state < 0) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
};

int main() {
    cin >> check;
    Solution so;
    so.guessNumber(check);
}
