class Queue {
public:
    stack<int> sta;
    stack<int> sta1;
    // Push element x to the back of queue.
    void push(int x) {
        sta.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!sta.empty()){
            sta1.push(sta.top());
            sta.pop();
        }
        sta1.pop();
        while(!sta1.empty()){
            sta.push(sta1.top());
            sta1.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while(!sta.empty()){
            sta1.push(sta.top());
            sta.pop();
        }
        int a=sta1.top();
        while(!sta1.empty()){
            sta.push(sta1.top());
            sta1.pop();
        }
        return a;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (sta.empty());
    }
};