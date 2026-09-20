public class ReverseLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }


    static Node reverse(Node head) {

        if (head == null || head.next == null) {
            return head;
        }

        Node newHead = reverse(head.next);
        head.next.next = head;
        head.next = null;

        return newHead;
    }


    static void printList(Node head) {

        while (head != null) {
            System.out.print(head.data + " -> ");
            head = head.next;
        }

        System.out.println("null");
    }


    public static void main(String[] args) {

        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        System.out.println("Original List:");
        printList(head);

        head = reverse(head);
        
        System.out.println("Reversed List:");
        printList(head);
    }
}