class Stack {
public:
    // Push element x onto stack.
    queue<int> tmp;
    queue<int> tmp1;
    void push(int x) {
        tmp.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int a=tmp.size();
        for(int i=0;i<a-1;i++)
        {
            tmp1.push(tmp.front());
            tmp.pop();
        }
        tmp.pop();
        for(int i=0;i<a-1;i++){
            tmp.push(tmp1.front());
            tmp1.pop();
        }
        
        
        
    }

    // Get the top element.
    int top() {
        
       return  tmp.back();
       
    }

    // Return whether the stack is empty.
    bool empty() {
        return tmp.empty();
    }
};