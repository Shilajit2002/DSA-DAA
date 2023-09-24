package SimpleQueue;

class Queue<T> {
    private T arr[];
    private int front, rear, count;

    //  Default Constructor
    public Queue() {
        this.arr = (T[]) (new Object[10]);
        this.front = -1;
        this.rear = -1;
        this.count = 0;
    }

    //  IsFull Method
    public boolean isFull() {
        if (this.rear == arr.length-1) {
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

    //  IncreaseSize
    private void increaseSize() {
        T temp[] = (T[]) (new Object[this.arr.length * 2]);
        for (int i = front; i <= rear; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }

    //  Enqueue
    public boolean enqueue(T val) {
        if (isFull()) {
            increaseSize();
        }

        //  If there have no element in the Queue
        if (this.front == -1 && this.rear == -1) {
            this.arr[++front] = val;
            rear++;
            count++;
            return true;
        }

        //  If there have an element in the Queue
        this.arr[++rear] = val;
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
        front++;
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

        for (int i = front; i <= rear; i++) {
            str += "| " + this.arr[i] + " |";
        }
        return str;
    }
}

