package Merge;

import java.util.Arrays;
import java.util.Scanner;

class Merging<T> {
    private T arr1[];
    private T arr2[];
    private T newArr[];

    public Merging(T[] arr1, T[] arr2) {
        this.arr1 = arr1;
        this.arr2 = arr2;
    }

    public T[] getArr1() {
        return arr1;
    }

    public void setArr1(T[] arr1) {
        this.arr1 = arr1;
    }

    public T[] getArr2() {
        return arr2;
    }

    public void setArr2(T[] arr2) {
        this.arr2 = arr2;
    }

    public T[] getNewArr() {
        return newArr;
    }

    public void setNewArr(T[] newArr) {
        this.newArr = newArr;
    }

    @Override
    public String toString() {
        return "First Array : " + Arrays.toString(arr1) + "\nSecond Array : " + Arrays.toString(arr2) +
                "\nMerged Array : " + Arrays.toString(newArr);
    }

    public void mergingArray() {
        this.newArr = (T[]) (new Object[this.arr1.length + this.arr2.length]);

        int i, j;

        for (i = 0; i < arr1.length; i++) {
            this.newArr[i] = arr1[i];
        }

        for (j = 0; j < arr2.length; j++, i++) {
            this.newArr[i] = arr2[j];
        }
    }
}

public class MergeArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Total no. of Elements for First Array = ");
        int n = sc.nextInt();

        Integer arr1[] = new Integer[n];
        System.out.print("Enter Elements : ");
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = sc.nextInt();
        }

        System.out.print("Enter Total no. of Elements for Second Array = ");
        int n1 = sc.nextInt();

        Integer arr2[] = new Integer[n];
        System.out.print("Enter Elements : ");
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = sc.nextInt();
        }

        Merging<Integer> MI = new Merging<Integer>(arr1, arr2);

        MI.mergingArray();

        System.out.println(MI);
    }
}
