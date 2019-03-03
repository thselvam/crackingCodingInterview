class MyCircularDeque {
public:
    vector <int> queue;
    int front;
    int rear;
    int size;
    int q_length;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        queue.resize(k);
        front = 0;
        rear = 1;
        size = k;
        q_length = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }

        queue.at(front) = value;
        q_length++;
        front = ((front-1) == -1)?size-1:front-1;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }

        queue.at(rear) = value;
        q_length++;
        rear = (rear == (size-1))?0:rear+1;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }

        front = (front == size-1)?0:front+1;
        q_length--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear == 0)?size-1:rear-1;
        q_length--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;

        return queue.at(front==(size-1)?0:front+1);

    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;

        return queue.at(rear==0?size-1:rear-1);
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (q_length == 0)
            return true;
        else
            return false;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (q_length == size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
