package CircularQueue;

public class CQueue<T> {
    private T arr[];
    private int front, rear, count;

    //  Default Constructor
    public CQueue(int n) {
        this.arr = (T[]) (new Object[n]);
        this.front = -1;
        this.rear = -1;
        this.count = 0;
    }

    //  IsFull Method
    public boolean isFull() {
        if ((this.rear + 1) % arr.length == this.front) {
            return true;
        }
        return false;
    }

    //  isEmpty Method
    public boolean isEmpty() {
        if (this.front == -1 && this.rear == -1) {
            return true;
        }
        return false;
    }

    //  Enqueue
    public boolean enqueue(T val) {
        if (isFull()) {
            return false;
        }

        //  If there have no element in the Queue
        if (this.front == -1 && this.rear == -1) {
            this.arr[++front] = val;
            rear++;
            count++;
            return true;
        }

        //  If there have an element in the Queue
        this.rear = (this.rear + 1) % arr.length;
        this.arr[rear] = val;
        count++;
        return true;
    }

    //  Dequeue
    public T dequeue() {
        if (isEmpty()) {
            return null;
        }

        T val;
        //  If front and rear both are same position
        if (this.front == this.rear) {
            val = this.arr[front];
            front = rear = -1;
            count--;
            return val;
        }

        //  If front and rear both are not same position
        val = this.arr[front];
        this.front = (this.front + 1) % arr.length;
        count--;
        return val;
    }

    //  Peek Element
    public T peek() {
        if (isEmpty()) {
            return null;
        }
        return this.arr[front];
    }

    //  Total Elements in the Queue
    public int totalElements() {
        return count;
    }

    //  Display Queue
    public String display() {
        String str = "";
        if (isEmpty()) {
            return null;
        }

        int i = front;

        while (i != rear) {
            str += "| " + arr[i] + " |";
            i = (i + 1) % arr.length;
        }
        str += "| " + arr[rear] + " |";
        return str;
    }
}
