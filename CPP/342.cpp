class Solution {
public:
    bool isPowerOfFour(int num) {
    	if (num == 0) {
    		return false;
    	}
    	if (num == 1) {
    		return true;
    	}
        int left = num;
        int remainer = 0;
        while (left != 1 && remainer == 0) {
        	remainer = left % 4;
        	left /= 4;
        }
        return remainer == 0;
    }
};