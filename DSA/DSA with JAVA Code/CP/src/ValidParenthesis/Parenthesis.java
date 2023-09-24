package ValidParenthesis;

import java.util.Objects;
import java.util.Scanner;
import java.util.Stack;

public class Parenthesis {

    //  Match Parenthesis Module
    public static boolean matchParenthesis(String br, String nbr) {
        //  Check First Bracket
        if (Objects.equals(br, "(") && Objects.equals(nbr, ")")) {
            return true;
        }
        //  Check Second Bracket
        else if (Objects.equals(br, "{") && Objects.equals(nbr, "}")) {
            return true;
        }
        //  Check Third Bracket
        else if (Objects.equals(br, "[") && Objects.equals(nbr, "]")) {
            return true;
        }
        return false;
    }

    //  Is Valid Module
    public boolean isValid(String s) {
        //  Create Stack Collection
        Stack<String> ST = new Stack<String>();

        //  Traversing the Input String
        for (int i = 0; i < s.length(); i++) {
            //  Take One by One Character from the String
            String curr = String.valueOf(s.charAt(i));

            //  Check is it Opening Brackets or not
            if (curr.equals("(") || curr.equals("{") || curr.equals("[")) {
                //  If yes then Push into the Stack
                ST.push(curr);
            }
            //  Check is it Closing Brackets or not
            else if (curr.equals(")") || curr.equals("}") || curr.equals("]")) {
                //  Check the Stack is Empty or Not
                if (ST.isEmpty()) {
                    return false;
                }
                //  If the Stack is not Empty
                else {
                    //  Pop the Current Value
                    String val = ST.pop();
                    //  Match Current Bracket with Popped Bracket
                    if (!matchParenthesis(val, curr)) {
                        return false;
                    }
                }
            }
        }

        //  Check the Stack is Empty or Not
        if (ST.isEmpty()) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Expression : ");
        String s = sc.next();
        Parenthesis P = new Parenthesis();
        System.out.println(P.isValid(s) ? "** The Parentheses is Matching **" :
                "`~` The Parentheses is not Matching `~`");
    }
}
