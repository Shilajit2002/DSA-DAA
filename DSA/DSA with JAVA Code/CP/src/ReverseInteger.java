import java.util.Scanner;

/*
7. Reverse Integer
        Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go
        outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

        Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

        Example 1:

        Input: x = 123
        Output: 321
        Example 2:

        Input: x = -123
        Output: -321
        Example 3:

        Input: x = 120
        Output: 21


        Constraints:

        -231 <= x <= 231 - 1
*/
/*The time complexity of the given reverse function is O(log10(x)), where x is the input integer.

Let's analyze the code step by step:

The function starts by checking if the input integer, x, is negative. This operation takes constant time, O(1).

If x is negative, it is multiplied by -1, which also takes constant time, O(1).

The function initializes reverseVal and digit to zero, which is a constant-time operation, O(1).

The while loop iterates as long as x is greater than zero. In each iteration, it performs the following operations:

a. It checks if reverseVal is about to overflow by comparing it with Integer.MAX_VALUE / 10 and Integer.MIN_VALUE / 10. This comparison is a constant-time operation, O(1).

b. It calculates the digit by taking the modulus of x with 10. This operation takes constant time, O(1).

c. It updates reverseVal by multiplying it by 10 and adding the digit. This operation takes constant time, O(1).

d. It updates x by dividing it by 10. This operation takes constant time, O(1).

The number of iterations in the while loop is determined by the number of digits in x, which is roughly log10(x). Therefore, the time complexity of the while loop is O(log10(x)).

Finally, the function checks if isNegative is true and multiplies reverseVal by -1 if necessary. These operations take constant time, O(1).

In summary, the dominant factor in the time complexity of the reverse function is the number of digits in the input integer, x. Therefore, the time complexity is O(log10(x)).*/
public class ReverseInteger {
    public int reverse(int x) {
        boolean isNegative = false;
        if (x < 0) {
            isNegative = true;
            x *= -1;
        }
        int reverseVal = 0;
        int digit = 0;
        while (x > 0) {
            if (reverseVal > Integer.MAX_VALUE / 10 || reverseVal < Integer.MIN_VALUE / 10) {
                return 0;
            }
            digit = x % 10;
            reverseVal = reverseVal * 10 + digit;
            x = x / 10;
        }
        if (isNegative) {
            reverseVal *= -1;
        }
        return reverseVal;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number = ");
        int x = sc.nextInt();
        ReverseInteger RI = new ReverseInteger();
        System.out.println("Reverse Number = " + RI.reverse(x));
    }
}
