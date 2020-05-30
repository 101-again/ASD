package com.company;

import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        Queue<Integer> queue = new Queue<>();
        Deque<Integer> deque = new Deque<>();
        Scanner scanner = new Scanner(System.in);

        int choice = 0;
        while(choice!=4) {
            System.out.println("1) stack");
            System.out.println("2) queue");
            System.out.println("3) deque");
            System.out.println("4) exit");
            choice = scanner.nextInt();
            //Stack
            switch (choice) {
                case 1: {
                    System.out.println("toString: " + stack.toString());
                    stack.push(1);
                    System.out.println("stack after push: " + stack);
                    System.out.println("peek element: " + stack.peek());
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                    System.out.println("peek element: " + stack.peek());
                    System.out.println("isEmpty check: " + stack.isEmpty());
                    stack.push(1);
                    System.out.println("stack after push: " + stack);
                    stack.push(2);
                    System.out.println("stack after push: " + stack);
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                    stack.push(3);
                    System.out.println("stack after push: " + stack);
                    stack.push(4);
                    System.out.println("stack after push: " + stack);
                    System.out.println("stack size: " + stack.getSize());
                    stack.push(5);
                    System.out.println("stack after push: " + stack);
                    System.out.println("isEmpty check: " + stack.isEmpty());
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                    System.out.println("stack size: " + stack.getSize());
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                    stack.pop();
                    System.out.println("stack after pop: " + stack);
                }
                //Queue
                break;
                case 2: {
                    System.out.println("queue: " + queue);
                    queue.enqueue(1);
                    System.out.println("queue after enqueue: " + queue);
                    queue.enqueue(2);
                    System.out.println("queue after enqueue: " + queue);
                    queue.enqueue(3);
                    System.out.println("queue after enqueue: " + queue);
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    queue.enqueue(4);
                    System.out.println("queue after enqueue: " + queue);
                    queue.enqueue(5);
                    System.out.println("queue after enqueue: " + queue);
                    System.out.println("queue size: " + queue.getSize());
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    System.out.println("peek element: " + queue.peek());
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    System.out.println("peek element: " + queue.peek());
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    System.out.println("queue size: " + deque.getSize());
                    queue.dequeue();
                    System.out.println("queue after dequeue: " + queue);
                    System.out.println("isEmpty check:  " + queue.isEmpty());
                    queue.enqueue(1);
                    System.out.println("queue after enqueue: " + queue);
                    System.out.println("isEmpty check: " + queue.isEmpty());
                }
                break;
                //Deque
                case 3: {
                    deque.push(1);
                    System.out.println("deque after push: " + deque);
                    deque.push(2);
                    System.out.println("deque after push: " + deque);
                    deque.push(3);
                    System.out.println("deque after push: " + deque);
                    deque.push(4);
                    System.out.println("deque after push: " + deque);
                    deque.push(5);
                    System.out.println("deque after push: " + deque);
                    deque.push(6);
                    System.out.println("isEmpty check: " + deque.isEmpty());
                    System.out.println("deque after push: " + deque);
                    System.out.println("toString: " + deque.toString());
                    System.out.println("deque: " + deque);
                    deque.pop();
                    System.out.println("deque after pop: " + deque);
                    System.out.println("deque: " + deque);
                    deque.eject();
                    System.out.println("deque after eject: " + deque);
                    deque.eject();
                    System.out.println("deque after eject: " + deque);
                    deque.inject(7);
                    System.out.println("deque after inject: " + deque);
                    System.out.println("deque: " + deque);
                    deque.inject(8);
                    System.out.println("deque after inject: " + deque);
                    System.out.println("deque after peekFirst: " + deque.peekFirst());
                    System.out.println("deque after peekLast: " + deque.peekLast());
                }
                break;

                case 4: {
                    System.out.println("Exit");
                }
                break;
                default: System.out.println("error");
            }
        }

    }

}
