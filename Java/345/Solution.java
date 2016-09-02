public class Solution {
    public boolean isVowel(char each) {
        if (each == 'a' || each == 'e' || each == 'i' || each == 'o' || each == 'u') {
            return true;
        }
        if (each == 'A' || each == 'E' || each == 'I' || each == 'O' || each == 'U') {
            return true;
        }
        return false;
    }
    public String reverseVowels(String ch) {
        char[] s = ch.toCharArray();
        int start = 0, end = s.length - 1;
        while(start < end) {
            while(!isVowel(s[start])) {
                start++;
                if (start > s.length - 1) {
                    return new String(s);
                }
            }
            while(!isVowel(s[end])) {
                end--;
                if (end < 0) {
                    return new String(s);
                }
            }
            if (start >= end) {
                return new String(s);
            }
            s[start] = (char) (s[start] ^ s[end]);
            s[end] = (char) (s[start] ^ s[end]);
            s[start] = (char) (s[start] ^ s[end]);
            start++;
            end--;
        }
        return new String(s);
    }
}