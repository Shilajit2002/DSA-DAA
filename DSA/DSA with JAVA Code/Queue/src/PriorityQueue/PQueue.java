package PriorityQueue;

class PQueue<T> {
    private T arr[];
    private int Parr[];
    private int front, rear, count;
    int index = 0;

    //  Default Constructor
    public PQueue() {
        this.arr = (T[]) (new Object[10]);
        this.Parr = new int[10];
        this.front = -1;
        this.rear = -1;
        this.count = 0;
    }

    //  IsFull Method
    public boolean isFull() {
        if (this.rear == arr.length - 1) {
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
        int Ptemp[] = new int[this.Parr.length * 2];
        for (int i = front; i <= rear; i++) {
            temp[i] = arr[i];
            Ptemp[i] = Parr[i];
        }
        arr = temp;
        Parr = Ptemp;
    }

    //  Enqueue
    public boolean enqueue(T val, int pri) {
        if (isFull()) {
            increaseSize();
        }

        //  If there have no element in the Queue
        if (this.front == -1 && this.rear == -1) {
            this.arr[++front] = val;
            this.Parr[front] = pri;
            rear++;
            count++;
            return true;
        }

        //  If there have an element in the Queue
        this.arr[++rear] = val;
        this.Parr[rear] = pri;
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
        val = peek();
        for (int k = index, l = index + 1; l < arr.length; k++, l++) {
            arr[k] = arr[l];
            Parr[k] = Parr[l];
        }
        rear--;
        count--;
        return val;
    }

    //  Peek Element
    public T peek() {
        if (isEmpty()) {
            return null;
        }

        //  Find the Highest Priority Element
        int max = Integer.MIN_VALUE;
        for (int i = front; i < rear; i++) {
            if (max < Parr[i]) {
                max = Parr[i];
                index = i;
            }
        }
        return arr[index];
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

    //  Display Priority
    public String displayPri() {
        String pri = "";

        for (int i = front; i <= rear; i++) {
            pri += "- " + this.Parr[i] + " -";
        }
        return pri;
    }
}
