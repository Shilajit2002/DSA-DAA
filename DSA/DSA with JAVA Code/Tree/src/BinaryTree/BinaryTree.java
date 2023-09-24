package BinaryTree;

import java.util.*;

//  Node Class
class Node<T> {
    //  Data
    private T data;
    //  Left and Right Node
    private Node<T> left, right;

    public Node(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public Node<T> getLeft() {
        return left;
    }

    public void setLeft(Node<T> left) {
        this.left = left;
    }

    public Node<T> getRight() {
        return right;
    }

    public void setRight(Node<T> right) {
        this.right = right;
    }
}

//  Binary Tree Class
class BinaryTree<T> {
    //  Root Node
    private Node<T> root;
    public boolean flag = false;

    public BinaryTree() {
        this.root = null;
    }

    public Node<T> getRoot() {
        return root;
    }

    public void setRoot(Node<T> root) {
        this.root = root;
    }

    //  Insert Data for Creating a Tree
    public static Integer insertData() {
        Scanner sc = new Scanner(System.in);
        Integer val = sc.nextInt();
        return val;
    }

    //  Create Binary Tree Method
    public Node<T> createBinaryTree(Node<T> R, T data) {
        //  If Data is -1 then the Node is null
        if (data.equals((-1))) {
            return null;
        }

        R = new Node<T>(data);

        System.out.print("Enter Left data for " + data + " or press -1 for no Data : ");
        //  Recursively Call the Method for Set the Left Data
        R.setLeft(createBinaryTree(R, (T) insertData()));

        System.out.print("Enter Right data for " + data + " or press -1 for no Data : ");
        //  Recursively Call the Method for Set the Right Data
        R.setRight(createBinaryTree(R, (T) insertData()));

        //  Return the Tree
        return R;
    }

    //  PreOrder Traversal
    public void preOrder(Node<T> root) {
        //  If root null then return
        if (root == null)
            return;

        //  Root Data
        System.out.print(root.getData() + " ");
        //  Go to Left Node Recursively
        preOrder(root.getLeft());
        //  After that Go to Right Node Recursively
        preOrder(root.getRight());
    }

    //  InOrder Traversal
    public void inOrder(Node<T> root) {
        //  If root null then return
        if (root == null)
            return;

        //  Go to Left Node First Recursively
        inOrder(root.getLeft());
        //  Root Data
        System.out.print(root.getData() + " ");
        //  After that Go to Right Node Recursively
        inOrder(root.getRight());
    }

    //  PostOrder Traversal
    public void postOrder(Node<T> root) {
        //  If root null then return
        if (root == null)
            return;

        //  Go to Left Node First Recursively
        postOrder(root.getLeft());
        //  After that Go to Right Node Recursively
        postOrder(root.getRight());
        //  Root Data
        System.out.print(root.getData() + " ");
    }

    //  Get Height of the Tree
    public int getHeight(Node<T> root) {
        if (root == null) return 0;
        return 1 + Math.max(getHeight(root.getLeft()), getHeight(root.getRight()));
    }

    //  Search in Binary Tree
    public boolean searchData(Node<T> root, T val) {
        if (root == null) {
            return false;
        } else {
            if (val.equals(root.getData())) {
                flag = true;
            }
            if (!flag && root.getLeft() != null) {
                searchData(root.getLeft(), val);
            }
            if (!flag && root.getRight() != null) {
                searchData(root.getRight(), val);
            }
        }
        return flag;
    }

    //  InOrder Predecessor
    public static <T> T inOrderPre(Node<T> root) {
        while (root.getRight() != null) {
            root = root.getRight();
        }
        return root.getData();
    }

    //  Delete a Node in Binary Tree
    public Node<T> deleteNode(Node<T> root, T key) {
        if (root == null) {
            return null;
        }
        //  If the Node is Found
        if (key.equals(root.getData())) {
            flag = true;
            //  If the Node have only Right Child
            if (root.getLeft() == null) {
                return root.getRight();
            }
            //  If the Node have only Left Child
            else if (root.getRight() == null) {
                return root.getLeft();
            }
            //  If the Node have both Left & Right Child then Call the InOrder Predecessor Method
            root.setData(inOrderPre(root.getRight()));
            //  Then recursively call the delete method for delete the InOrder Predecessor Data
            root.setRight(deleteNode(root.getRight(), root.getData()));
        }
        //  If the Node is not Found then go to Left SubTree Recursively
        root.setLeft(deleteNode(root.getLeft(), key));
        //  If the Node is not Found then go to Right SubTree Recursively
        root.setRight(deleteNode(root.getRight(), key));
        return root;
    }

    //  Print Traverse Pre Order Tree
    public void traversePreOrder(StringBuilder sb, String padding, String pointer, Node<T> root) {
        if (root != null) {
            sb.append(padding);
            sb.append(pointer);
            sb.append(root.getData());
            sb.append("\n");

            StringBuilder paddingBuilder = new StringBuilder(padding);
            paddingBuilder.append("│  ");

            String paddingForBoth = paddingBuilder.toString();
            String pointerForRight = "└──";
            String pointerForLeft = (root.getRight() != null) ? "├──" : "└──";

            traversePreOrder(sb, paddingForBoth, pointerForLeft, root.getLeft());
            traversePreOrder(sb, paddingForBoth, pointerForRight, root.getRight());
        }
    }

    //  Print Tree Structure
    public void printTree(Node<T> root) {
        StringBuilder sb = new StringBuilder();
        traversePreOrder(sb, "", "", root);
        System.out.println(sb.toString());
    }
}
