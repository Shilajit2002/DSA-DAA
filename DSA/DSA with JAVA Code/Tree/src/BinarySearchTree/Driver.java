package BinarySearchTree;

import java.util.*;

public class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        BinarySearchTree BST = new BinarySearchTree();
        int choice;

        do {
            System.out.print("1.Insert Data in BST\n2.Pre-Order Traversal\n3.Post-Order Traversal" +
                    "\n4.In-Order Traversal" + "\n5.Search Data\n6.Height of the Tree\n7.Delete a Node" +
                    "\n8.Print Tree\n9.Exit\nEnter your choice : ");
            choice = sc.nextInt();
            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Node Data = ");
                    int val = sc.nextInt();
                    BST.setRoot(BST.createBinarySearchTree(BST.getRoot(), val));
                }
                case 2 -> {
                    if (BST.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BST.preOrder(BST.getRoot());
                        System.out.println();
                    }
                }
                case 3 -> {
                    if (BST.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BST.postOrder(BST.getRoot());
                        System.out.println();
                    }
                }
                case 4 -> {
                    if (BST.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BST.inOrder(BST.getRoot());
                        System.out.println();
                    }
                }
                case 5 -> {
                    System.out.print("Enter Data for Search = ");
                    int key = sc.nextInt();
                    if (BST.searchData(BST.getRoot(), key)) {
                        System.out.println(key + " is Present in the Binary Search Tree");
                    } else {
                        System.out.println(key + " is Not Present in the Binary Search Tree");
                    }
                }
                case 6 -> {
                    System.out.println("Height of the Binary Search Tree is = " + BST.getHeight(BST.getRoot()));
                }
                case 7 -> {
                    System.out.print("Enter Data for Delete = ");
                    int data = sc.nextInt();
                    BST.setRoot(BST.deleteNode(BST.getRoot(), data));
                    if (BST.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else if(BST.searchData(BST.getRoot(), data)){
                        System.out.println(data + " has been deleted from the Binary Search Tree");
                    }else{
                        System.out.println(data + " is Not Present in the Binary Search Tree");
                    }
                }
                case 8 -> {
                    if (BST.getRoot() == null) {
                        System.out.println("`~` Tree is Empty `~`");
                    } else {
                        BST.printTree(BST.getRoot());
                    }
                }
                case 9 -> {
                    System.out.println("Quiting....");
                }
                default -> {
                    System.out.println("`~`Invalid Choice`~`");
                }
            }
        } while (choice != 9);
    }
}
