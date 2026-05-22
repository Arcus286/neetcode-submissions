class MyStack {
public:
    deque<int> myQueue;
    MyStack() {
        
    }
    
    void push(int x) {
        myQueue.push_back(x);
    }
    
    int pop() {
        int a = myQueue.back();
        myQueue.pop_back();
        return a;
    }
    
    int top() {
        return myQueue.back();
    }
    
    bool empty() {
        return myQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */