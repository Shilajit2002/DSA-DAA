/*
***** LEET CODE STRINGS CP *****

* 3. Longest Substring Without Repeating Characters *

Q.Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

import java.util.Scanner;

public class LongestSubstring {

    //  First Process Take Much Time
//    public int lengthOfLongestSubstring(String s) {
//        int left = 0, right = 0;
//        StringBuilder temp = new StringBuilder();
//        int max = 0;
//
//        while (right < s.length()) {
//            char c = s.charAt(right);
//            if (!temp.toString().contains(String.valueOf(c))) {
//                temp.append(c);
//                System.out.println(temp);
//                max = Math.max(max, right - left + 1);
//                right++;
//            } else {
//                while (s.charAt(left) != c) {
//                    temp = new StringBuilder(temp.toString().replace(String.valueOf(s.charAt(left)), ""));
//                    left++;
//                }
//                temp = new StringBuilder(temp.toString().replace(String.valueOf(s.charAt(left)), ""));
//                left++;
//            }
//        }
//
//        return max;
//    }

    //  Better Process
    //  Time Complexity = O(n^2)
    //  Space Complexity = O(1)
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;

        for (int rP = 0, lP = 0; rP < s.length(); rP++) {
            int currentIndex = s.indexOf(s.charAt(rP), lP);
            if (currentIndex != rP) {
                lP = currentIndex + 1;
            }
            maxLength = Math.max(maxLength, rP - lP + 1);
        }
        return maxLength;
    }

    public static void main(String[] args) {
        LongestSubstring LS = new LongestSubstring();

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a String : ");
        String s = sc.next();

        System.out.println("Longest Substring Without Repeating Characters is : " + LS.lengthOfLongestSubstring(s));
    }
}
