public class searchaLL{
    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static boolean isSubList(Node list1, Node list2) {

        if (list1 == null) {
            return true;
        }

        while (list2 != null) {

            Node p1 = list1;
            Node p2 = list2;

            while (p1 != null && p2 != null && p1.data == p2.data) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) {
                return true;
            }

            list2 = list2.next;
        }

        return false;
    }

    static Node insert(Node head, int data) {

        Node newNode = new Node(data);
        if (head == null) {
            return newNode;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
        return head;
    }

    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }


    public static void main(String[] args) {

        // list1 = 10 -> 20
        Node list1 = null;
        list1 = insert(list1, 1);
        list1 = insert(list1, 2);

        // list2 = 5 -> 10 -> 20
        Node list2 = null;
        list2 = insert(list2, 1);
        list2 = insert(list2, 2);
        list2 = insert(list2, 1);
        list2 = insert(list2, 2);
        list2 = insert(list2, 3);
        list2 = insert(list2, 4);


        boolean result = isSubList(list1, list2);

        if (result) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}