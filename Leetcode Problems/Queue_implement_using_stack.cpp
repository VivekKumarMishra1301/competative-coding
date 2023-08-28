class MyStack
{
public:
    queue<int> q;
    int fl = 0;
    MyStack()
    {
    }
    void rev()
    {
        if (q.size() == 0)
        {
            // q.push(x);
            return;
        }
        int tmp = q.front();
        q.pop();
        rev();
        q.push(tmp);
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        rev();
        int tmp = q.front();
        q.pop();
        rev();
        return tmp;
    }

    int top()
    {
        rev();
        int tp = q.front();
        rev();
        return tp;
    }

    bool empty()
    {
        return q.empty();
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