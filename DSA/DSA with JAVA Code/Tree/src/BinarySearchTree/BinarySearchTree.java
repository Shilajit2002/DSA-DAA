package BinarySearchTree;

//  Node Class
class Node {
    //  Data
    private int data;
    //  Left and Right Node
    private Node left, right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Node getLeft() {
        return left;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getRight() {
        return right;
    }

    public void setRight(Node right) {
        this.right = right;
    }
}

//  Binary Tree Class
class BinarySearchTree {
    //  Root Node
    private Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    public Node getRoot() {
        return root;
    }

    public void setRoot(Node root) {
        this.root = root;
    }

    //  Create Binary Tree Method
    public Node createBinarySearchTree(Node root, int data) {

        if (root == null) {
            root = new Node(data);
            System.out.println(data + " is Inserted in the BST");
            return root;
        } else if (data < root.getData()) {
            root.setLeft(createBinarySearchTree(root.getLeft(), data));
        } else if (data > root.getData()) {
            root.setRight(createBinarySearchTree(root.getRight(), data));
        } else {
            System.out.println(data + " is already in BST");
        }

        return root;
    }

    //  PreOrder Traversal
    public void preOrder(Node root) {
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
    public void inOrder(Node root) {
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
    public void postOrder(Node root) {
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
    public int getHeight(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(getHeight(root.getLeft()), getHeight(root.getRight()));
    }

    //  Search in Binary Tree
    public boolean searchData(Node root, int key) {
        if (root == null) {
            return false;
        } else if (root.getData() == key) {
            return true;
        } else if (key < root.getData()) {
            return searchData(root.getLeft(), key);
        } else {
            return searchData(root.getRight(), key);
        }
    }

    //  InOrder Predecessor
    public static int inOrderPre(Node root) {
        while (root.getRight() != null) {
            root = root.getRight();
        }
        return root.getData();
    }

    //  InOrder Successor
    public static int inOrderSuc(Node root) {
        while (root.getLeft() != null) {
            root = root.getLeft();
        }
        return root.getData();
    }

    //  Delete a Node in Binary Tree
    public Node deleteNode(Node root, int key) {
        if (root == null) {
            return null;
        } else if (key < root.getData()) {
            root.setLeft(deleteNode(root.getLeft(), key));
        } else if (key > root.getData()) {
            root.setRight(deleteNode(root.getRight(), key));
        } else {
            // Case 1 and 2 => The Node to be Deleted is a leaf Node or Node has only right Child
            if (root.getLeft() == null) {
                return root.getRight();
            }
            // Case 1 and 2 => The Node to be Deleted is a leaf Node or Node has only left Child
            else if (root.getRight() == null) {
                return root.getLeft();
            }
            // Case 3 => The Node to be Deleted has two children using Inorder Predecessor
            root.setData(inOrderPre(root.getLeft()));
            //  Then recursively call the delete method for delete the InOrder Predecessor Data
            root.setLeft(deleteNode(root.getLeft(), root.getData()));

            /*
            // Case 3 => The Node to be Deleted has two children using Inorder Successor
            root.setData(inOrderSuc(root.getRight()));
            //  Then recursively call the delete method for delete the InOrder Successor Data
            root.setRight(deleteNode(root.getRight(), root.getData()));
             */

            /* For Case 3 we cannot use both process same time.When we use Predecessor then we comment our
            Successor Code and When we use Successor then we comment our Predecessor Code */
        }
        return root;
    }

    //  Print Traverse Pre Order Tree
    public void traversePreOrder(StringBuilder sb, String padding, String pointer, Node root) {
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
    public void printTree(Node root) {
        StringBuilder sb = new StringBuilder();
        traversePreOrder(sb, "", "", root);
        System.out.println(sb.toString());
    }
}
