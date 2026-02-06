class MyQueue {
    // Amortized O(1):
    // Each element is pushed once to input
    // move once to ouput from input
    // popped once from output
public:
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    void push(int x) {  //O(1)
        input.push(x);
    }
    
    int pop() {     // Amortized O(1)
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }
    
    int peek() {    // Amortized O(1)
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {  // O(1)
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */