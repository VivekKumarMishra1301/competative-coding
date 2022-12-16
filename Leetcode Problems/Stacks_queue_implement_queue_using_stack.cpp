class MyQueue
{
public:
    vector<int> hold;
    MyQueue()
    {
    }

    void push(int x)
    {
        hold.push_back(x);
    }

    int pop()
    {
        if (hold.size() == 0)
        {
            return 0;
        }
        int n = hold[0];
        for (int i = 0; i < hold.size() - 1; i++)
        {
            hold[i] = hold[i + 1];
        }
        hold.pop_back();
        return n;
    }

    int peek()
    {
        if (hold.size() == 0)
        {
            return 0;
        }

        return hold[0];
    }

    bool empty()
    {
        if (hold.size() == 0)
        {
            return true;
        }
        return false;
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