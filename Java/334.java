
public class Solution {
    /**
     * String 没有[]方法只能转换为char[]来进行下标访问符。
     * @param  s 传入值
     * @return   返回reverse String
     */
    public String reverseString(String s) {
        char[] ch = s.toCharArray();
        int start = 0;
        int end = ch.length - 1;
        while (start < end) {
            ch[start] = (char) (ch[start] ^ ch[end]);
            ch[end] = (char) (ch[start] ^ ch[end]);
            ch[start] = (char) (ch[start] ^ ch[end]);
            start++;
            end--;
        }
        return new String(ch);
    }
    public static void main(String[] args) {
        Solution so = new Solution();
        System.out.print(so.reverseString("Hello"));
    }
}