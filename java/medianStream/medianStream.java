import java.util.PriorityQueue;

public class medianStream {
    PriorityQueue<Integer> MinHeap = new PriorityQueue<>();
    PriorityQueue<Integer> MaxHeap = new PriorityQueue<>((a, b) -> b - a);

    public void add(int number) {
        if(MaxHeap.isEmpty() || number<=MaxHeap.peek()) {
            MaxHeap.add(number);
        }
        else {
            MinHeap.add(number);
        }
        if(MaxHeap.size() > MinHeap.size()+1) {
            MinHeap.add(MaxHeap.poll());

        }
        if(MinHeap.size() > MaxHeap.size()) {
            MaxHeap.add(MinHeap.poll());
        }

    }
    public float getMedian() {
        if(MaxHeap.size() == MinHeap.size()) {
            return (MaxHeap.peek()+MinHeap.peek())/2.0f;
        }
        else if(MaxHeap.size() > MinHeap.size()) {
            return MaxHeap.peek();
        }
        else {
            return MinHeap.peek();
        }
    }
    public static void main(String[] args) {
        medianStream ms = new medianStream();
        ms.add(1);
        ms.add(2);
        ms.add(3);
        ms.add(4);
        ms.add(5);
        // ms.add(6);
        // ms.add(7);
        // ms.add(8);
        // ms.add(9);
        System.out.println(ms.getMedian());
    }
    
}
