package SimpleQueue;

import java.util.Scanner;

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Queue<Integer> QI = new Queue<Integer>();

        int choice;

        do {
            System.out.print("1.Enqueue\n2.Dequeue\n3.Peek\n" +
                    "4.Total Elements in the Queue\n5.Display Queue\n6.Exit\nEnter your choice = ");
            choice = sc.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter Element = ");
                    Integer val = sc.nextInt();

                    if (QI.enqueue(val)) {
                        System.out.println(val + " is Enqueued");
                    }
                }
                case 2 -> {
                    Integer val = QI.dequeue();
                    if (val == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println(val + " is Dequeued");
                    }
                }
                case 3 -> {
                    if (QI.peek() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Front Element of the Queue is = " + QI.peek());
                    }
                }
                case 4 -> {
                    if (QI.totalElements() == 0) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("Total Elements in the Queue is = " + QI.totalElements());
                    }
                }
                case 5 -> {
                    if (QI.display() == null) {
                        System.out.println("Queue is Empty");
                    } else {
                        System.out.println("** Queue **");
                        System.out.println(QI.display());
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
