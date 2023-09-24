package BinaryTree;

import java.util.*;

public class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        BinaryTree<Integer> BT = new BinaryTree<Integer>();

        System.out.println("**** Create Binary Tree ****");
        System.out.print("Enter Root Data or press -1 for no Data : ");
        int val = sc.nextInt();
        BT.setRoot(BT.createBinaryTree(BT.getRoot(), val));

        int choice;

        do {
            System.out.print("1.Pre-Order Traversal\n2.Post-Order Traversal\n3.In-Order Traversal" +
                    "\n4.Search Data\n5.Height of the Tree\n6.Delete a Node\n7.Print Tree\n8.Exit\nEnter your choice : ");
            choice = sc.nextInt();
            switch (choice) {
                case 1 -> {
                    if (BT.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BT.preOrder(BT.getRoot());
                        System.out.println();
                    }
                }
                case 2 -> {
                    if (BT.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BT.postOrder(BT.getRoot());
                        System.out.println();
                    }
                }
                case 3 -> {
                    if (BT.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BT.inOrder(BT.getRoot());
                        System.out.println();
                    }
                }
                case 4 -> {
                    System.out.print("Enter Data for Search = ");
                    int data = sc.nextInt();
                    if (BT.searchData(BT.getRoot(), data)) {
                        System.out.println(data + " is Present in the Binary Tree");
                        BT.flag = false;
                    } else {
                        System.out.println(data + " is Not Present in the Binary Tree");
                    }
                }
                case 5 -> {
                    System.out.println("Height of the Binary Tree is = " + BT.getHeight(BT.getRoot()));
                }
                case 6 -> {
                    System.out.print("Enter Data for Delete = ");
                    int key = sc.nextInt();
                    BT.setRoot(BT.deleteNode(BT.getRoot(), key));
                    if (BT.getRoot() == null || !BT.flag) {
                        System.out.println(key + " is Not Present in the Binary Tree");
                    } else {
                        System.out.println(key + " has been deleted from the Binary Tree");
                        BT.flag = false;
                    }
                }
                case 7 -> {
                    if (BT.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BT.printTree(BT.getRoot());
                    }
                }
                case 8 -> {
                    System.out.println("Quiting....");
                }
                default -> {
                    System.out.println("`~`Invalid Choice`~`");
                }
            }
        } while (choice != 8);
    }
}
