package Insertion;

import java.util.Arrays;
import java.util.Scanner;

class Insert<T> {
    private T arr[];

    public Insert(T[] arr) {
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

    public void insertElement(T data, int pos) {
        T newArr[] = (T[]) (new Object[this.arr.length + 1]);

        for (int i = 0; i <= this.arr.length; i++) {
            if (i < pos - 1) {
                newArr[i] = this.arr[i];
            } else if (i == pos - 1) {
                newArr[i] = data;
            } else {
                newArr[i] = this.arr[i - 1];
            }
        }
        this.arr = newArr;
    }
}

public class ArrayInsertion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Integer arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        String arr1[] = {"Rahul", "Bob", "Alex", "Martin"};

        Insert<Integer> IT = new Insert<Integer>(arr);
        Insert<String> ST = new Insert<String>(arr1);

        // System.out.println(IT);
        System.out.println(ST);

        System.out.print("Are you want to Insert ? Y / N : ");
        String c = sc.next();

        while (c.equalsIgnoreCase("Y")) {
            System.out.print("Enter Element to be Inserted = ");

            //  Integer data = sc.nextInt();
            String data1 = sc.next();

            System.out.print("Enter Position of the Element = ");
            int pos = sc.nextInt();

            try {
                //  IT.insertElement(data, pos);
                ST.insertElement(data1, pos);

                //  System.out.println(IT);
                System.out.println(ST);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Please Enter Correct Position!!");
            }

            System.out.print("Are you want to Insert ? Y / N : ");
            c = sc.next();
        }
    }
}
