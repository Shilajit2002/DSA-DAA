package DoubleEndedQueue;

import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        DEQueue<Integer> DQ = new DEQueue<>(10);

        int choice;

        do {
            System.out.print("1.Enqueue from Front\n2.Enqueue from Rear\n3.Dequeue from Front\n4.Dequeue from Rear" +
                    "\n5.Get Front Element\n6.Get Rear Element\n7.Peek\n" +
                    "8.Total Elements in the Queue\n9.Display Queue\n10.Exit\nEnter your choice = ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Element = ");
                    Integer val = sc.nextInt();

                    if (DQ.enqueueFront(val)) {
                        System.out.println(val + " is Enqueued in the Front");
                    } else {
                        System.out.println("Queue is Full");
                    }
                }
                case 2 -> {
                    System.out.print("Enter Element = ");
                    Integer val = sc.nextInt();

                    if (DQ.enqueueRear(val)) {
                        System.out.println(val + " is Enqueued in the Rear");
                    } else {
                        System.out.println("Queue is Full");
                    }
                }
                case 3 -> {
                    Integer val = DQ.dequeueFront();
                    if (val == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println(val + " is Dequeued from the Front");
                    }
                }
                case 4 -> {
                    Integer val = DQ.dequeueRear();
                    if (val == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println(val + " is Dequeued from the Rear");
                    }
                }
                case 5 -> {
                    if (DQ.getFront() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Front Element of the Queue is = " + DQ.getFront());
                    }
                }
                case 6 -> {
                    if (DQ.getRear() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Rear Element of the Queue is = " + DQ.getRear());
                    }
                }
                case 7 -> {
                    if (DQ.peek() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Front Element of the Queue is = " + DQ.peek());
                    }
                }
                case 8 -> {
                    if (DQ.totalElements() == 0) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Total Elements in the Queue is = " + DQ.totalElements());
                    }
                }
                case 9 -> {
                    if (DQ.display() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("** Queue **");
                        System.out.println(DQ.display());
                    }
                }
                case 10 -> {
                    System.out.println("Quiting...");
                }
                default -> {
                    System.out.println("`~` Invalid Choice `~`");
                }
            }
        } while (choice != 10);
    }
}
