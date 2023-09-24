package Stack;

import java.util.Scanner;

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Stack<Integer> IS = new Stack<Integer>();

        int choice;

        do {
            System.out.print("1.Push Element\n2.Pop Element\n3.Peek Element\n" +
                    "4.Display Element\n5.Total Elements in the Stack\n6.Exit\nEnter your Choice : ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Element : ");
                    int i = sc.nextInt();
                    if (IS.push(i)) {
                        System.out.println(i + " Pushed in the Stack");
                    }
                }
                case 2 -> {
                    Integer i = IS.pop();
                    if (i == null) {
                        System.out.println("Stack Underflow");
                    } else {
                        System.out.println(i + " is Popped from the Stack");
                    }
                }
                case 3 -> {
                    Integer i = IS.peek();
                    if (i == null) {
                        System.out.println("Stack Underflow");
                    } else {
                        System.out.println("Top of the Stack Element is : " + i);
                    }
                }
                case 4 -> {
                    if (IS.display() == null) {
                        System.out.println("Stack Underflow");
                    } else {
                        System.out.println("** Stack **");
                        System.out.println(IS.display());
                    }
                }
                case 5 -> {
                    int t = IS.totalElements();
                    if (t == -1) {
                        System.out.println("No Elements in the Stack");
                    } else {
                        System.out.println("Total Elements in the Stack is = " + (t + 1));
                    }
                }
                case 6 -> {
                    System.out.println("Quiting...");
                }
                default -> System.out.println("Invalid Choice");
            }
            System.out.println("------------------------------------");
        } while (choice != 6);
    }
}
