package PriorityQueue;

import java.util.Scanner;

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        PQueue<Integer> PQ = new PQueue<>();

        int choice;

        do {
            System.out.print("1.Enqueue\n2.Dequeue\n3.Peek\n" +
                    "4.Total Elements in the Queue\n5.Display Queue\n6.Exit\nEnter your choice = ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Element = ");
                    Integer val = sc.nextInt();
                    System.out.print("Enter Priority = ");
                    int pri = sc.nextInt();

                    if (PQ.enqueue(val, pri)) {
                        System.out.println(val + " is Enqueued");
                    }
                }
                case 2 -> {
                    Integer val = PQ.dequeue();
                    if (val == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println(val + " is Dequeued");
                    }
                }
                case 3 -> {
                    if (PQ.peek() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Highest Priority Element of the Queue is = " + PQ.peek());
                    }
                }
                case 4 -> {
                    if (PQ.totalElements() == 0) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Total Elements in the Queue is = " + PQ.totalElements());
                    }
                }
                case 5 -> {
                    if (PQ.display() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("** Queue **");
                        System.out.println(PQ.display());
                        System.out.println(PQ.displayPri());
                    }
                }
                case 6 -> {
                    System.out.println("Quiting...");
                }
                default -> {
                    System.out.println("`~` Invalid Choice `~`");
                }
            }
        } while (choice != 6);
    }
}
