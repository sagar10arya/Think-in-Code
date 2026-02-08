class MinStack {
public:
    // TC: O(1), SC: O(N)
    stack<long long> st;
    long long mini;

    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val >= mini) st.push(val);
        else{
            st.push((long long) 2*val - mini);
            mini=val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topVal = st.top();
        st.pop();

        if(topVal < mini){
            // recover previous minimum
            mini = 2 * mini - topVal;
        }
    }
    
    int top() {
        long long topVal = st.top();
        if(topVal >= mini){
            return topVal;
        } else{
            return mini; // encoded value, actual top is mini
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */