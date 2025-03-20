class MinStack {
    Stack<Pair<Integer,Integer>> st;
    public MinStack() {
        st=new Stack<>();
    }
    
    public void push(int val) {
        int v=(st.empty())?val:Math.min(val,st.peek().getValue());
        st.push(new Pair<>(val,v));
    }
    
    public void pop() {
        st.pop();
    }
    
    public int top() {
        if(st.empty()) return -1;
        return st.peek().getKey();
    }
    
    public int getMin() {
        if(st.empty()) return -1;
        return st.peek().getValue();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */