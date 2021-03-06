class Queue {
private:
    stack<int> in_stack;
    stack<int> out_stack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        in_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (out_stack.size() == 0) {
            while(in_stack.size() != 0) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        out_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out_stack.size() == 0) {
            while (in_stack.size() != 0) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return !(out_stack.size() != 0 || in_stack.size() != 0);
    }
};
