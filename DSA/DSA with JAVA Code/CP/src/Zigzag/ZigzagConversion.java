/*

Leet Code - 6. Zigzag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to
display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"

Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

 */

package Zigzag;

import java.util.ArrayList;
import java.util.Scanner;

public class ZigzagConversion {
    public String convert(String s, int numRows) {
        //  If the String and Row length is 1 then return that String
        if (numRows == 1 || s.length() == 1) {
            return s;
        }

        ArrayList<String> zigString = new ArrayList<String>();

        //  Set Empty String in ArrayList
        for (int i = 0; i < numRows; i++) {
            zigString.add("");
        }

        //  Set Flag
        boolean flag = false;
        //  Set Index
        int i = 0;

        //  Main Logic
        for (char c : s.toCharArray()) {
            //  Add Each Character in the ArrayList
            zigString.set(i, zigString.get(i) + c);
            //  If it is first index or last index then flag will be changed
            if (i == 0 || i == numRows - 1) {
                //  If i is 0 then it will be true
                //  If i is numRows-1 then it will be false
                flag = !flag;
            }

            //  If flag true then i will be increased
            if (flag) {
                i += 1;
            }
            //  Otherwise Decreased
            else {
                i -= 1;
            }
        }

        //  Convert ArrayList to String
        String newZig = "";
        for (String zs : zigString) {
            newZig += zs;
        }

        return newZig;
    }

    public static void main(String[] args) {
        ZigzagConversion ZC = new ZigzagConversion();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a String : ");
        String s = sc.next();
        System.out.print("Enter Number of Rows : ");
        int numRows = sc.nextInt();

        String zigzagString = ZC.convert(s, numRows);

        System.out.println("Zigzag String : " + zigzagString);
    }
}
