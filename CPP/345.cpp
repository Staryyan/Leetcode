class Solution {
public:
	bool isVowel(char each) {
		if (each == 'a' || each == 'e' || each == 'i' || each == 'o' || each == 'u') {
			return true;
		}
		if (each == 'A' || each == 'E' || each == 'I' || each == 'O' || each == 'U') {
			return true;
		}
		return false;
	}
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
        	while(!isVowel(s[start])) {
        		start++;
        	}
        	while(!isVowel(s[end])) {
        		end--;
        	}
        	if (start >= end) {
        		return s;
        	}
        	s[start] = (char)s[start] ^ s[end];
        	s[end] = (char)s[start] ^ s[end];
        	s[start] = (char)s[start] ^ s[end];
      		start++;
      		end--;
        }
        return s;
    }
};
