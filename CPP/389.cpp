class Solution {
public:
    char findTheDifference(string s, string t) {
    	char total = s[0];
        for (int i = 1; i < s.length(); ++i) {
        	total ^= s[i];
        }
        for (int i = 0; i < t.length(); ++i) {
        	total ^= t[i];
        }
        return total;
    }
};