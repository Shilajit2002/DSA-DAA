package Stack;

class Stack<T> {
    private T arr[];
    private int top;

    //  Constructor
    public Stack() {
        this.arr = (T[]) (new Object[10]);
        this.top = -1;
    }

    //  IsEmpty Function
    public boolean isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    //  IsFull Function
    public boolean isFull() {
        if (top == arr.length - 1) {
            return true;
        }
        return false;
    }

    //  Increase the size of the array
    private void increaseSize() {
        T temp[] = (T[]) (new Object[top * 2]);
        for (int i = 0; i <= top; i++) {
            temp[i] = this.arr[i];
        }
        this.arr = temp;
    }

    //  Push Element
    public boolean push(T val) {
        if (isFull()) {
            increaseSize();
        }
        this.arr[++top] = val;
        return true;
    }

    //  Pop Element
    public T pop() {
        if (isEmpty()) {
            return null;
        }
        T val = this.arr[top];
        top--;
        return val;
    }

    //  Peek Element
    public T peek() {
        if (isEmpty()) {
            return null;
        }
        return this.arr[top];
    }

    //  Total Elements in the Stack
    public int totalElements() {
        return top;
    }

    //  Display the Elements
    public String display() {
        String str = "";
        if (isEmpty()) {
            return null;
        }
        for (int i = top; i >= 0; i--) {
            str += "| " + arr[i] + " |\n";
        }
        return str;
    }
}

