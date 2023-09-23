class MyQueue {
    stack<int>s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    // 4 2 5 1 9
    int pop() {
        vector<int>v;
        while(s.size()>1)
        {
            v.push_back(s.top());
            s.pop();
        }
        int x = s.top();
        s.pop();
        for(int i=v.size()-1;i>=0;i--)
        {
            s.push(v[i]);
        }
        return x;
    }
    
    int peek() {
        vector<int>v;
        while(s.size()>1)
        {
            v.push_back(s.top());
            s.pop();
        }
        int x = s.top();
        for(int i=v.size()-1;i>=0;i--)
        {
            s.push(v[i]);
        }
        return x;
    }
    
    bool empty() {
        return s.size()==0;
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