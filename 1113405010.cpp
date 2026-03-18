#include <iostream>
using namespace std;

// ==================== Stack ====================
class Stack {
private:
    int top;
    int capacity;
    int* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow，無法加入 " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " 已加入 Stack，時間複雜度: O(1)" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow，Stack 為空" << endl;
            return;
        }
        cout << arr[top] << " 已從 Stack 移除，時間複雜度: O(1)" << endl;
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack 為空" << endl;
            return;
        }
        cout << "Stack 頂端元素: " << arr[top] << "，時間複雜度: O(1)" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack 為空" << endl;
            return;
        }
        cout << "Stack 內容(由上到下): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "，時間複雜度: O(n)" << endl;
    }
};

// ==================== Queue ====================
class Queue {
private:
    int front;
    int rear;
    int capacity;
    int* arr;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow，無法加入 " << value << endl;
            return;
        }
        arr[++rear] = value;
        cout << value << " 已加入 Queue，時間複雜度: O(1)" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow，Queue 為空" << endl;
            return;
        }
        cout << arr[front] << " 已從 Queue 移除，時間複雜度: O(1)" << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue 為空" << endl;
            return;
        }
        cout << "Queue 前端元素: " << arr[front] << "，時間複雜度: O(1)" << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue 為空" << endl;
            return;
        }
        cout << "Queue 內容(由前到後): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "，時間複雜度: O(n)" << endl;
    }
};

// ==================== 主程式 ====================
int main() {
    cout << "===== Stack 測試 =====" << endl;
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();

    cout << endl;

    cout << "===== Queue 測試 =====" << endl;
    Queue q(5);

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    q.peek();
    q.dequeue();
    q.display();

    cout << endl;
    cout << "===== 時間複雜度總整理 =====" << endl;
    cout << "Stack push: O(1)" << endl;
    cout << "Stack pop: O(1)" << endl;
    cout << "Stack peek: O(1)" << endl;
    cout << "Stack display: O(n)" << endl;
    cout << "Queue enqueue: O(1)" << endl;
    cout << "Queue dequeue: O(1)" << endl;
    cout << "Queue peek: O(1)" << endl;
    cout << "Queue display: O(n)" << endl;

    return 0;
}
