/**
 * if the number is the power of two,
 * its most maximal bit must be one and others are zero.
 */
#include <math.h>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(n & (n - 1)));
    }
};