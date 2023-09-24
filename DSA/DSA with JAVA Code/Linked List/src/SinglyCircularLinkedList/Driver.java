package SinglyCircularLinkedList;

import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SCircularLinkedList<Integer> SI = new SCircularLinkedList<>();

        int choice;

        do {
            System.out.print("1.Insert Data\n2.Insert Data at Specific Position\n3.Remove Data\n4.Size" +
                    "\n5.Display\n6.Clear LinkedList\n7.Reverse List\n8.Exit\nEnter Your Choice : ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Data = ");
                    int data = sc.nextInt();
                    if (SI.insertData(data)) {
                        System.out.println(data + " Inserted in the List");
                    }
                }
                case 2 -> {
                    System.out.print("Enter Data = ");
                    int data = sc.nextInt();
                    System.out.print("Enter Position = ");
                    int pos = sc.nextInt();
                    if (SI.insertDataPos(data, pos)) {
                        System.out.println(data + " Inserted in the List");
                    } else {
                        System.out.println("Enter Correct Position !!");
                    }
                }
                case 3 -> {
                    System.out.print("Enter Data = ");
                    int data = sc.nextInt();
                    if (SI.removeData(data)) {
                        System.out.println(data + " Removed from the List");
                    } else {
                        System.out.println(data + " is not Present in the List !!");
                    }
                }
                case 4 -> {
                    System.out.println("Size of the Linked List = " + SI.size());
                }
                case 5 -> {
                    System.out.println("** Linked List **");
                    SI.display();
                }
                case 6 -> {
                    SI.clear();
                    System.out.println("-- Linked List has been Cleared --");
                }
                case 7 -> {
                    SI.reverseList();
                }
                case 8 -> {
                    System.out.println("Quiting...");
                }
                default -> {
                    System.out.println("`~` Invalid Choice `~`");
                }
            }
        } while (choice != 8);
    }
}
