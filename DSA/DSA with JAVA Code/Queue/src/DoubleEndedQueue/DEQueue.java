package DoubleEndedQueue;

class DEQueue<T> {
    private T arr[];
    private int front, rear, count;

    //  Default Constructor
    public DEQueue(int n) {
        this.arr = (T[]) (new Object[n]);
        this.front = -1;
        this.rear = -1;
        this.count = 0;
    }

    //  IsFull Method
    public boolean isFull() {
        if (this.front == this.rear + 1 || (this.front == 0 && this.rear == arr.length - 1)) {
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

    //  Enqueue from Front
    public boolean enqueueFront(T val) {
        if (isFull()) {
            return false;
        }

        //  If the Queue is Empty
        if (this.front == -1 && this.rear == -1) {
            this.arr[++front] = val;
            this.rear++;
            count++;
            return true;
        }
        //  If the Front is 0 position then shift front to last index of the Circular Array
        else if (this.front == 0) {
            this.front = arr.length - 1;
            this.arr[front] = val;
            count++;
            return true;
        }
        //  Shift front to previous index
        this.front--;
        this.arr[front] = val;
        count++;
        return true;
    }

    //  Enqueue from Rear
    public boolean enqueueRear(T val) {
        if (isFull()) {
            return false;
        }

        //  If the Queue is Empty
        if (this.front == -1 && this.rear == -1) {
            this.arr[++front] = val;
            this.rear++;
            count++;
            return true;
        }
        //  If the Rear is last position then shift Rear to 0 index of the Circular Array
        else if (this.rear == arr.length - 1) {
            this.rear = 0;
            this.arr[rear] = val;
            count++;
            return true;
        }
        //  Shift Rear to next index
        this.rear++;
        this.arr[rear] = val;
        count++;
        return true;
    }

    //  Dequeue from Front
    public T dequeueFront() {
        if (isEmpty()) {
            return null;
        }

        T val;
        //  If Front and Rear both are same position
        if (this.front == this.rear) {
            val = this.arr[front];
            front = rear = -1;
            count--;
            return val;
        }
        //  If Front is last Position then shift Front to 0 index
        else if (this.front == arr.length - 1) {
            val = this.arr[front];
            this.front = 0;
            count--;
            return val;
        }
        //  Shift Front to next index
        val = this.arr[front];
        front++;
        count--;
        return val;
    }

    //  Dequeue from Rear
    public T dequeueRear() {
        if (isEmpty()) {
            return null;
        }

        T val;
        //  If Front and Rear both are same position
        if (this.front == this.rear) {
            val = this.arr[front];
            front = rear = -1;
            count--;
            return val;
        }
        //  If Rear is 0 Position then shift Front to last index
        else if (this.rear == 0) {
            val = this.arr[rear];
            this.rear = arr.length - 1;
            count--;
            return val;
        }
        //  Shift Rear to previous index
        val = this.arr[rear];
        rear--;
        count--;
        return val;
    }

    //  Get Front Element
    public T getFront() {
        if (isEmpty()) {
            return null;
        }
        return this.arr[front];
    }

    //  Get Rear Element
    public T getRear() {
        if (isEmpty()) {
            return null;
        }
        return this.arr[rear];
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
