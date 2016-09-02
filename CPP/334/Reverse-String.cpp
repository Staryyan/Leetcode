/**
 * 使用了^运算的自反性来交换数据。		
 */
class Solution {
public:
    string reverseString(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
        	s[start] = (char)s[start] ^ s[end];
        	s[end] = (char)s[start] ^ s[end];
        	s[start] = (char)s[start] ^ s[end];
        	start++;
        	end--;
        }
        return s;
    }
};
