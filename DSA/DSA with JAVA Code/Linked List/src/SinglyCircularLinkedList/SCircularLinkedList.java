package SinglyCircularLinkedList;

//  Node Class for Referring Next Node in the LinkedList
class Node<T> {
    private T data;
    private Node<T> next;

    //  Constructor
    public Node(T data) {
        this.data = data;
        this.next = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T data) {
        this.data = data;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}

public class SCircularLinkedList<T> {
    private Node<T> head;
    private int length = 0;

    public SCircularLinkedList() {
        this.head = null;
    }

    //  Insert Data in the Linked List
    public boolean insertData(T data) {
        //  Create New Node
        Node<T> newNode = new Node<T>(data);

        //  If the List is Empty
        if (this.head == null) {
            this.head = newNode;
            this.head.setNext(this.head);
            length++;
            return true;
        }

        //  If the List is Not Empty
        Node<T> temp = head;
        while (temp.getNext() != head) {
            temp = temp.getNext();
        }
        temp.setNext(newNode);
        temp.getNext().setNext(head);
        length++;
        return true;
    }

    //  Insert Data in the Linked List at the Specific Position
    public boolean insertDataPos(T data, int pos) {
        if (pos > 0 && pos <= length + 1) {
            //  Create New Node
            Node<T> newNode = new Node<T>(data);

            //  Insert Data at Beginning of the Linked List
            if (pos == 1) {
                //  If the List is Empty
                if (head == null) {
                    this.head = newNode;
                    this.head.setNext(head);
                    length++;
                    return true;
                }

                //  If the List is Not Empty
                Node<T> temp = head;
                while (temp.getNext() != head) {
                    temp = temp.getNext();
                }
                newNode.setNext(head);
                head = newNode;
                temp.setNext(head);
                length++;
                return true;
            }

            //  Insert Data at the Specific Position of the Linked List
            if (head != null) {
                Node<T> prev = head;
                Node<T> next = head.getNext();
                int count = 2;

                while (count != pos) {
                    prev = next;
                    next = next.getNext();
                    count++;

                    //  Insert Data at the End of the Linked List
                    if (next == head) {
                        prev.setNext(newNode);
                        prev.getNext().setNext(head);
                        length++;
                        return true;
                    }
                }

                //  Insert the Data at the Specific Position
                prev.setNext(newNode);
                newNode.setNext(next);
                length++;
                return true;
            }
            return false;
        }
        return false;
    }

    //  Remove the Data from the Linked List
    public boolean removeData(T data) {
        if (head != null) {
            Node<T> prev = head;
            Node<T> next = head.getNext();

            //  Delete Data from the Beginning of the Linked List

            // Convert value to be compared into Strings
            // and then compare using
            // String1.equals(String2) method
            if (String.valueOf(head.getData()).equals(String.valueOf(data))) {
                Node<T> temp = head;
                while (temp.getNext() != head) {
                    temp = temp.getNext();
                }
                head = head.getNext();
                temp.setNext(head);
                length--;
                return true;
            }

            //  Delete Data from any Position
            while (next != head) {
                if (String.valueOf(next.getData()).equals(String.valueOf(data))) {
                    break;
                }
                prev = next;
                next = next.getNext();

                //  If the Data is not present in the Linked List
                if (next == head) {
                    return false;
                }
            }
            //  Delete the Data
            next = next.getNext();
            prev.setNext(next);
            length--;
            return true;
        }
        return false;
    }

    //  Size of the LinkedList
    public int size() {
        return this.length;
    }

    //  Clear the LinkedList
    public void clear() {
        this.head = null;
        this.length = 0;
    }

    //  Reverse the LinkedList
    public void reverseList() {
        Node<T> prev = head;
        Node<T> current = head;
        Node<T> next = head;

        while (next.getNext() != head) {
            next = next.getNext();
            current.setNext(prev);
            prev = current;
            current = next;
        }
        current.setNext(prev);
        prev = current;
        Node<T> temp = prev;
        while (temp.getNext() != head) {
            temp = temp.getNext();
        }
        head = prev;
        temp.setNext(head);
        //  After Reverse the List Display the List
        display();
    }

    //  Display the LinkedList
    public void display() {
        String str = "";
        if (head != null) {
            Node<T> temp = head;
            while (temp.getNext() != head) {
                str += temp.getData() + " -> ";
                temp = temp.getNext();
            }
            str += temp.getData();
            System.out.println(str);
        } else {
            System.out.println("`~` Empty List `~`");
        }
    }
}
