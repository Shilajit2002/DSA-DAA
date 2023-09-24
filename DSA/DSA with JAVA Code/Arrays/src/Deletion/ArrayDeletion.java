package Deletion;

import java.util.Arrays;
import java.util.Scanner;

class Delete<T> {
    private T arr[];

    public Delete(T[] arr) {
        this.arr = arr;
    }

    public T[] getArr() {
        return arr;
    }

    public void setArr(T[] arr) {
        this.arr = arr;
    }

    @Override
    public String toString() {
        return "Array : " + Arrays.toString(arr);
    }

    public void deleteElement(int pos) {
        if (this.arr.length != 0) {
            T newArr[] = (T[]) (new Object[this.arr.length - 1]);

            if (pos > 0 && pos <= arr.length) {
                for (int i = 0; i < this.arr.length - 1; i++) {
                    if (i < pos - 1) {
                        newArr[i] = this.arr[i];
                    } else if (i == pos - 1) {
                        newArr[i] = this.arr[i + 1];
                    } else {
                        newArr[i] = this.arr[i + 1];
                    }
                }
                this.arr = newArr;
            } else {
                throw new ArrayIndexOutOfBoundsException();
            }
        } else {
            System.out.println("Array is Empty!!");
        }
    }
}

public class ArrayDeletion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Integer arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        Delete<Integer> DT = new Delete<Integer>(arr);

        System.out.println(DT);

        System.out.print("Are you want to Delete ? Y / N : ");
        String c = sc.next();

        while (c.equalsIgnoreCase("Y")) {
            System.out.print("Enter Position of the Element = ");
            int pos = sc.nextInt();

            try {
                DT.deleteElement(pos);
                System.out.println(DT);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Please Enter Correct Position!!");
            }

            System.out.print("Are you want to Insert ? Y / N : ");
            c = sc.next();
        }
    }
}
